#include <cs50.h>
#include <stdio.h>

// I found this project extra tricky and satisfying.
// I managed to accept higher than 8 input,
// and even added a snarky input control to avoid
// things getting out of hand.
// I then increased modularity and tightened the code.
// I then further increased modularity and tightened the code, harder.
// The last two parts were the hardest, calling a function and
// passing an arguement for the next fuction at the same time eluded me
// for a good bit. I had to use the rubber duck a couple times, but mostly
// debugged via terminal error correction.

/*
    1/22/2025
    Oh yeah, I was being a dick to whoever had to read this code if anyone ever did.
    Can you spot the funny parts?
*/


void printSpace(void)
{
    printf(" ");
}

void printBrick(void)
{
    printf("#");
}

void bricksToBePrinted(int bricksToPrint)
{
    for (int b = bricksToPrint; b > 0; b--)
    {
        printBrick();
    }
}

int getStairsize(void)
{
    int height;
    int inputIsInvalid;
    for (inputIsInvalid = 0; inputIsInvalid < 1;)
    {
        height = get_int("How high would you like to jump today mario? \n");
        if (height > 0 && height < 45)
        {
            inputIsInvalid++;
        }
        else
        {
            printf("Even your legs might give out if you try to jump that high Mario.\n");
        }
    }
    return height;
}
void printStairs(int height)
{
    // This loop will determine how many spaces and bricks
    // are needed to print current line correctly, and execute.
    int currentLine;
    for (currentLine = 1; currentLine <= height; currentLine++)
    {
        int spacesTillBrick = (height - currentLine);
        int bricksToPrint = (height - spacesTillBrick);
        for (int s = spacesTillBrick; s > 0; s--)
        {
            printSpace();
        }
        bricksToBePrinted(bricksToPrint);
        for (int gapSpaces = 2; gapSpaces > 0; gapSpaces--)
        {
            printSpace();
        }
        bricksToBePrinted(bricksToPrint);
        printf("\n");
    }
}
int main(void)
{
    int height = getStairsize();
    printStairs(height);
}
