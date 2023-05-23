#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structura pentru reprezentarea unei reguli în gramatica regulată
struct Rule {
    string lhs; // Partea stângă a regulii
    vector<vector<string>> rhs; // Partea dreaptă a regulii
};

// Funcția pentru citirea gramaticii regulate din fișier și returnarea ei sub forma unui vector de reguli
vector<Rule> read_grammar(const string& file_name) {
    vector<Rule> grammar;
    ifstream file(file_name);
    string line;
    while (getline(file, line)) {
        // Eliminăm caracterele newline ("\n") de la sfârșitul liniei
        line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());

        istringstream iss(line);
        string rule;
        iss >> rule;
        string lhs = rule.substr(0, rule.find("->"));
        string rhs = rule.substr(rule.find("->") + 2);
        istringstream rhs_stream(rhs);
        string token;
        vector<vector<string>> productions;
        while (getline(rhs_stream, token, '|')) {
            istringstream token_stream(token);
            vector<string> production;
            string symbol;
            while (token_stream >> symbol) {
                production.push_back(symbol);
            }
            productions.push_back(production);
        }
        grammar.push_back({lhs, productions});
    }
    return grammar;
}

// Funcția care verifică dacă un cuvânt este acceptat de gramatica regulată
bool accepts(const vector<Rule>& grammar, const string& symbol, const string& word) {
    if (word.empty()) {
        for (const Rule& rule : grammar) {
            if (rule.lhs == symbol) {
                for (const vector<string>& production : rule.rhs) {
                    if (production.size() == 1 && production[0] == "lambda") {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    for (const Rule& rule : grammar) {
        if (rule.lhs == symbol) {
            for (const vector<string>& production : rule.rhs) {
                size_t i = 0;
                bool match = true;
                for (const string& prodSymbol : production) {
                    if (i >= word.length() || (prodSymbol != "lambda" && word.substr(i, prodSymbol.length()) != prodSymbol)) {
                        match = false;
                        break;
                    }
                    i += prodSymbol.length();
                }
                if (match && accepts(grammar, production.back(), word.substr(i))) {
                    return true;
                }
            }
        }
    }

    return false;
}


vector<pair<string, bool>> check_words(const vector<Rule>& grammar, const vector<string>& words) {
    vector<pair<string, bool>> results;

    for (const string& word : words) {
        bool accepted = accepts(grammar, "S", word);
        results.push_back(make_pair(word, accepted));
    }

    return results;
}

int main() {
    string grammar_file_name;
    cout << "Enter the Regular Grammar file name: ";
    cin >> grammar_file_name;

    // Citirea gramaticii din fișier
    vector<Rule> grammar = read_grammar(grammar_file_name);

    cin.ignore();  // Ignorăm newline-ul rămas în buffer după citirea numelui fișierului

    string words_file_name;
    cout << "Enter the file name that contains the words to check: ";
    getline(cin, words_file_name);

    // Citirea cuvintelor din fișier
    vector<string> words;
    ifstream words_file(words_file_name);
    if (words_file.is_open()) {
        string word;
        while (getline(words_file, word)) {
            if (!word.empty()) {
                // Eliminăm caracterele newline ("\n") și spațiile goale de la sfârșitul cuvântului
                word.erase(word.find_last_not_of(" \r\n") + 1);
                words.push_back(word);
            }
        }
        words_file.close();
    } else {
        cout << "Unable to open file: " << words_file_name << endl;
        return 1; // Terminăm programul cu o eroare
    }

    // Verificarea cuvintelor
    vector<pair<string, bool>> results = check_words(grammar, words);

    // Scrierea rezultatelor în fișier
    string output_file_name = "results.txt";
    ofstream output_file(output_file_name);
    for (const auto& result : results) {
        output_file << "The word '" << result.first << "' is ";
        if (result.second) {
            output_file << "accepted by the grammar." << endl;
        } else {
            output_file << "not accepted by the grammar." << endl;
        }
    }

    cout << "Results written to " << output_file_name << endl;

    return 0;
}
