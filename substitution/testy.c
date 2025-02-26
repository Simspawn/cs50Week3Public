// use to test code snippets, temp hold for code snippets, etc etc


#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int validate_Key(string key);
void cipher(string plaintext, string key, char *cipherText);
int main(int argc, string argv[])
{
    printf("what\n");
    string key = argv[1];
    string plainText;
    if (argc == 2)
    {
        if (validate_Key(key) != 0)
        {
                printf("validate loop\n");
            return 1;
        }
    } else { printf("Program must be run with alphabetic key.\n"); return 1;}
    printf("what2\n");
    plainText = get_string("plaintext:\n");
    int length = strlen(plainText);
    char cipherText[length +1];
    cipher(plainText, key, cipherText);
    printf("\nciphertext: %s\n\n\n", cipherText);
    printf("\n");
    printf("\n");

}

bool validate_Key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        printf("Invalid Key length, must be 26 alphabetic chars.\n");
        return 1;
    }
    bool seen[26] = {false};
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]))
        {
            char c = tolower(key[i]);
            int index = c - 'a';
            if (seen[index])
            {
                printf("Key contains duplicate chars.\n"); return 1;
            }
            seen[index] = true;
        } else printf("Key must be alphabetic.\n"); return 1;
    }
return true;
}

void cipher(string plainText, string key, char *cipherText)
{

    int length = strlen(plainText), plainTextIndex = 0;
    for (int i = 0; i < length; i++)
    {

        if (isupper(plainText[i]))
        {
            plainTextIndex = plainText[i] - 'A';
            cipherText[i] = (key[plainTextIndex]);
        }
        else if (islower(plainText[i]))
        {
            plainTextIndex = plainText[i] - 'a';
            cipherText[i] = (key[plainTextIndex]);
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
printf("\n");
cipherText[length] = '\0';
}



void cipher(string plainText, char upperKey[], char lowerKey[], char *cipherText)
{
    int length2 = strlen(plainText), plainTextIndex = 0;
    for (int i = 0; i < length2; i++)
    {
        if (isupper(plainText[i]))
        {
            plainTextIndex = plainText[i] - 'A';
            cipherText[i] = upperKey[plainTextIndex];
        }
        else if (islower(plainText[i]))
        {
            plainTextIndex = plainText[i] - 'a';
            cipherText[i] = lowerKey[plainTextIndex];
        }
        else
        {
            cipherText[i] = plainText[i];
        }
    }
    cipherText[length2] = '\0';
}
