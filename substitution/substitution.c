#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define FIRST_LOWERCASE_CHAR 97
#define FIRST_UPPERCASE_CHAR 65

int validateInput(string key);
void encrypt(string plainText, string key);

int main(int argc, string argv[])
{
    // First prompt if there are two arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // Check if entered key has valid length
    string key = argv[1];
    int valid = validateInput(key);
    if (valid != 0)
    {
        return 1;
    }

    // Key is valid
    string plainText = get_string("plaintext: ");
    // Print ciphertext
    printf("ciphertext: ");
    encrypt(plainText, key);
}

int validateInput(string key)
{
    int keyLength = strlen(key);
    if (keyLength != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Check if all letters are entered and that all characters are alphabetical
    // (convert them to uppercase first)
    bool noRepeatedLetters = true;
    bool onlyAlphaCharacters = true;
    for (int i = 0; i < keyLength; i++)
    {
        if (!isalpha(key[i]))
        {
            // There is a non alphabetical character
            onlyAlphaCharacters = false;
            break;
        }
        // Compare with the rest of characters
        for (int j = 0; j < keyLength; j++)
        {
            // Skip when comparing the same index (will always be true)
            if (j == i)
            {
                continue;
            }
            if (toupper(key[i]) == toupper(key[j]))
            {
                // Letter is repeated
                noRepeatedLetters = false;
                break;
            }
        }
    }

    if (!onlyAlphaCharacters)
    {
        printf("Key must only contain letters.\n");
        return 1;
    }

    if (!noRepeatedLetters)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    // Valid
    return 0;
}

void encrypt(string plainText, string key)
{
    // Iterate over plainText and replace every character with the one in the key
    int textLength = strlen(plainText);
    int keyLength = strlen(key);
    for (int i = 0; i < textLength; i++)
    {
        // First check if character is a letter
        if (isalpha(plainText[i]))
        {
            // Check if uppercase or lowercase
            if (isupper(plainText[i]))
            {
                // Subtract 65 from it to get key index
                int index = plainText[i] - FIRST_UPPERCASE_CHAR;
                printf("%c", toupper(key[index]));
            }
            else
            {
                // Subtract 97 from it to get key index
                int index = plainText[i] - FIRST_LOWERCASE_CHAR;
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // Just print the character.
            printf("%c", plainText[i]);
        }
    }
    printf("\n");
}
