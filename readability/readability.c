#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Full disclosure: While I had an easier time with syntax, getting the math to math right was a lot
// harder on this one than others.
float letter_counter(string s);
float word_counter(float spaces);
float sentence_counter(string s);
float space_counter(string s);

int main()
{
    float letterCount, spaceCount, wordCount, sentenceCount;
    float readingLevel;
    string text = get_string("Enter some text to test it's reading level: \n");
    letterCount = letter_counter(text);
    spaceCount = space_counter(text);
    sentenceCount = sentence_counter(text);
    wordCount = word_counter(spaceCount);
    readingLevel = (0.0588 * ((letterCount / wordCount) * 100) -
                    0.296 * ((sentenceCount / wordCount) * 100) - 15.8);
    float roundedReadingLevel = round(readingLevel);
    printf("Letters = %.0f \nSpaces = %.0f \nWordcount = %.0f\nSentences = %.0f\n", letterCount,
           spaceCount, wordCount, sentenceCount);
    if (roundedReadingLevel > 15)
    {
        printf("Grade 16+\n");
    }
    else if (roundedReadingLevel > 1)
    {
        printf("Grade %.0f\n", roundedReadingLevel);
    }
    else
    {
        printf("Before Grade 1\n");
    }
}

float letter_counter(string s)
{
    float letterCount = 0;
    for (int i = 0; s[i]; i++)
    {
        if (isalpha(s[i]))
        {
            letterCount++;
        }
    }
    return letterCount;
}

float space_counter(string s)
{
    float spacesCount = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ' ')
            ++spacesCount;
    }
    return spacesCount;
}

float sentence_counter(string s)
{
    float sentenceCount = 0;
    for (int i = 0; s[i]; i++)
    {
        if ((s[i]) == '.' || (s[i]) == '!' || (s[i]) == '?')
        {
            ++sentenceCount;
        }
    }
    return sentenceCount;
}

float word_counter(float spacesCount)
{
    float wordCount = (spacesCount + 1);
    return wordCount;
}
