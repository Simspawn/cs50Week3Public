#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int letter_counter(string s);
int word_counter(int x);
int sentence_counter(string s);
int space_counter(string s);
int readability(int x, int y, int z);
int letterCount, spaceCount, wordCount, sentenceCount, readingLevel;

int main()
{

        string text = get_string("Enter some text to test it's reading level: \n");
        letterCount = letter_counter(text);
        spaceCount = space_counter(text);
        sentenceCount = sentence_counter(text);
        wordCount = word_counter(spaceCount);

        printf("Letters = %i \nSpaces = %i \nWordcount = %i\nSentences = %i\n", letterCount, spaceCount, wordCount, sentenceCount);
        readingLevel = round( 0.0588 * ((letterCount / wordCount) * 100) - 0.296 * ((sentenceCount / wordCount) * 100) - 15.8);
        if (readingLevel > 15)
                {
                        printf("Grade 16+ \n");
                }
        else
        {
                printf("Grade %i\n", readingLevel);
        }

}

int letter_counter(string s)
{
        int x = 0;
        for (int i = 0; s[i]; i++)
        {
                if isalpha(s[i])
                        {
                             ++letterCount;
                        }
        }
return letterCount;
}

int space_counter(string s)
{
        for (int i =0; s[i]; i++)
                {
                        if (s[i] == ' ')
                        ++spaceCount;
                }
return spaceCount;
}

int sentence_counter(string s)
{
        for (int i = 0; s[i]; i++)
        {
                if (ispunct(s[i]))
                {
                        ++sentenceCount;
                }
        }
return sentenceCount;
}

int word_counter(int s)
{
        wordCount = (++s);
        return wordCount;
}

