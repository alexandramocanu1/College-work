def read_grammar(file_name):
    # Citește o gramatică regulată din fișierul dat și o returnează ca un dicționar
    grammar = {}
    with open(file_name, "r") as f:
        for line in f:
            parts = line.strip().split("->")
            lhs = parts[0].strip()
            rhs = parts[1].strip().split("|")

            if lhs not in grammar:
                grammar[lhs] = []
            for rule in rhs:
                grammar[lhs].extend(rule.split())

    return grammar


def accepts(grammar, symbol, word):
    if not word:
        return 'lambda' in grammar[symbol]

    if len(word) == 1:
        last_letter = word[0]
        for transition in grammar[symbol]:
            if len(transition) == 1 and transition[0] == last_letter:
                return True

    for transition in grammar[symbol]:
        if len(transition) > 1 and transition[0] == word[0]:
            if accepts(grammar, transition[1], word[1:]):
                return True

    return False


def check_words(grammar, words):
    results = []
    for word in words:
        accepted = accepts(grammar, "S", word)
        results.append((word, accepted))
    return results


def main():
    grammar_file_name = input("Introduceți numele fișierului cu gramatica regulată: ").strip()
    grammar = read_grammar(grammar_file_name)

    words_file_name = input("Introduceți numele fișierului care conține cuvintele de verificat: ").strip()
    with open(words_file_name, "r") as f:
        words = [line.strip() for line in f]

    results = check_words(grammar, words)

    for word, accepted in results:
        if accepted:
            print(f"Cuvântul '{word}' este acceptat de gramatică.")
        else:
            print(f"Cuvântul '{word}' nu este acceptat de gramatică.")


if __name__ == "__main__":
    main()
