#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char word[5];
    printf("Enter a word: \n");
    scanf("%5s", word);
    int length = strlen(word);
/*  if (length > 5)
    {
        word[5] = '\0';
    }*/
    printf("Your word was: %s \n", word);
}
/*
int num = 100;
num += 100;
num -= 50;
num *= 2;
num /=2;
num %= 10;
*/
