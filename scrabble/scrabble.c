#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int score(string word);
int main()
{
    string word1 = get_string("Player1, enter a word: "),
           word2 = get_string("\nPlayer2, enter a word: ");
    int player1 = score(word1), player2 = score(word2);
    if (player1 > player2)
    {
        printf("Player 1 wins! \n");
    }
    else if (player1 < player2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie!\n");
    }
    return 0;
}
int score(string word)
{
    int score = 0;
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isalpha(word[i]))
        {
            score += points[tolower(word[i]) - 'a'];
        }
    }
    return score;
}
