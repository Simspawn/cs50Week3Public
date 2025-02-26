#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int points[7] = {1, 2, 3, 4, 5, 8, 10};
int score(string word);

int main()
{
    string player1 = get_string("Player1, enter a word: "), player2 = get_string("\nPlayer2, enter a word: ");
    score(player1);
    score(player2);
    if (player1 > player2)
    {
        printf("Player1 wins! \n");
    } else if (player1 < player2)
        {
            printf("Player2 wins! \n");
        } else
            {
                printf("Tie!");
            }
return 0;
}

int score(string word)
{
    int score = 0;
    int length = strlen(word);
    for (int i = 0; i <= length; i++)
    {
        if (isalpha(word[i]))
        {
            int index = tolower(word[i]) - 'a';
            // Following are letters worth 1 point. I could use a switch here, however I don't think it would be as concise in this use as it's only a 7 chain if-elseif-else vs 26 cases.
            if (index == 0 || index == 4 || index == 8 || index == 11 || index == 13 || index == 14 || index == 17 || index == 18 ||index == 19 || index == 20)
            {
                score += points[0];
            } else if (index == 3 || index == 6) // Letters worth 2 points.
                {
                    score += points[1];
                } else if (index == 1 || index == 2 || index == 12 || index == 15) // Letters worth 3 points.
                    {
                        score += points[2];
                    } else if (index == 5 || index == 7 || index == 21 || index == 22 || index == 24) // Letters worth 4 points.
                        {
                            score += points[3];
                        } else if (index == 9 || index == 23) // Letters worth 8 points.
                            {
                                score += points[5];
                            } else if (index == 16 || index == 25)
                                {
                                    score += points[6];
                                } else
                                    {
                                        score += points[4];
                                    }
        }
    }
return score;
}
