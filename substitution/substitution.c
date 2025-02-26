#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This one was by far the hardest to finally get working correctly.
// I had to get help from the ddb and chatgpt far far far too many times.
// I'm stoked I finally got it working, but I'm pretty upset with myself for having such a hard
// time. (No, I didn't use any code produced by chatgpt, I asked it why's and how's and what's)
// Yes, I am aware this is bad code. I may rewrite it in the future. Prolly not though.
int validate_Key(string key);
void cipher(string plaintext, char *cipherText, char upperKey[], char lowerKey[]);
int main(int argc, string argv[])
{
    if (argc != 2)
        return 1;
    string key = argv[1];
    int length = strlen(key);
    if (validate_Key(key) == 1)
        return 1;
    string plainText;
    plainText = get_string("plaintext:\n");
    int length2 = strlen(plainText);
    char cipherText[length2], lowerKey[length], upperKey[length];
    for (int i = 0; i < length; i++)
    {
        upperKey[i] = (toupper(key[i]));
        lowerKey[i] = (tolower(key[i]));
    }
    cipher(plainText, upperKey, lowerKey, cipherText);
    printf("ciphertext: %s\n", cipherText);
}

int validate_Key(string key)
{
    int length = strlen(key);
    bool seen[26] = {false};
    if (length != 26)
        return 1;
    for (int i = 0; i < length; i++)
    {
        char c = tolower(key[i]);
        int index = c - 'a';
        if (!isalpha(key[i]))
        {
            printf("Key must be alphabetic.");
            return 1;
        }
        else if (seen[index])
        {
            printf("Key contains duplicate chars.\n");
            return 1;
        }
        else
            seen[index] = true;
    }
    return 0;
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
// Rubber Duck tip below.
// bool seen[26] = {false};

// for (int i = 0; i < length; i++)
//{
//     char c = tolower(argv[1][i]);
//     int index = c - 'a';
//     if (seen[index])
//     {
//  Character already seen, key is invalid
//        printf("Duplicate character found in key.\n");
//        return 1;
//    }
//    seen[index] = true;
//}

// Loop of unkonwn purpose.
// for (int i = 0; i < length)
// char key[length];
// for (int i = length; i > 0; i--)
//{
//    key[i] = argv[1][i];
//}
