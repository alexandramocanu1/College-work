#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt_word(char *word, char *shuffled_word)
{
    strcpy(shuffled_word, word);
    int len = strlen(word);
    for (int i = 0; i < len - 1; i++)
    {
        int j = i + rand() % (len - i);
        char temp = shuffled_word[i];
        shuffled_word[i] = shuffled_word[j];
        shuffled_word[j] = temp;
    }
}

void encrypt_file(const char *input_file, const char *output_file)
{
    FILE *f_in = fopen(input_file, "r");
    FILE *f_out = fopen(output_file, "w");

    if (f_in == NULL || f_out == NULL)
    {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char word[100];
    while (fscanf(f_in, "%s", word) != EOF)
    {
        char shuffled_word[100];
        encrypt_word(word, shuffled_word);
        fprintf(f_out, "%s ", shuffled_word);
    }

    fclose(f_in);
    fclose(f_out);
}

void decrypt_word(char *word, char *shuffled_word)
{
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        int j;
        for (j = 0; j < len; j++)
        {
            if (word[i] == shuffled_word[j])
            {
                break;
            }
        }
        shuffled_word[j] = word[i];
    }
}

void decrypt_file(const char *input_file, const char *output_file)
{
    FILE *f_in = fopen(input_file, "r");
    FILE *f_out = fopen(output_file, "w");

    if (f_in == NULL || f_out == NULL)
    {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char word[100];
    char shuffled_word[100];
    while (fscanf(f_in, "%s", word) != EOF)
    {
        decrypt_word(word, shuffled_word);
        fprintf(f_out, "%s ", shuffled_word);
    }

    fclose(f_in);
    fclose(f_out);
}

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));

    if (argc != 4)
    {
        printf("Usage: %s <input_file> <output_file> <1 for encryption, 2 for decryption>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int choice = atoi(argv[3]);

    if (choice == 1)
    {
        encrypt_file(input_file, output_file);
        printf("Encryption completed.\n");
    }
    else if (choice == 2)
    {
        decrypt_file(input_file, output_file);
        printf("Decryption completed.\n");
    }
    else
    {
        printf("Invalid choice. Please provide 1 for encryption or 2 for decryption.\n");
        return 1;
    }

    return 0;
}
