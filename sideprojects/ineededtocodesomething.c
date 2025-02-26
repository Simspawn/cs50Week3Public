#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// we'll work on this eventually, prolly. Gonna need it for our first interactive fiction.
// Lets make a basic 4 question trivia game, but introduce some twists.
// Randomly pick question order.

// declaring some global variables
int score = 0;

// declaring some functions that are defined after int main().
int q42();

int main ()

{
    q42();
}

int q42()
{
    int answer = 0;
    do
    {
        answer = get_int("What is the answer to life, the universe, and everything? \n");
        if (answer != 42)
        {
            printf("Try again. \n");
        }

        if (answer == 42)
        {
            printf("That is correct. \n");
            score++;
            answer = 1;
        }
    }
    while (answer != 1);


    return score;
}
