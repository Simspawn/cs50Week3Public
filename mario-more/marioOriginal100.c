#include <cs50.h>
#include <stdio.h>

// I found this project extra tricky and satisfying.
// I managed to accept for higher input,
// and even added a snarky input control.

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

int main(void)
{

    int currentLine;
    int inputIsInvalid;
    int height;

    for (inputIsInvalid = 0; inputIsInvalid < 1;)
    {
        height = get_int("How high would you like to jump today mario? \n");
        if (height > 0 && height < 31)
        {
            inputIsInvalid++;
        }

        else
            printf("We could prolly do it, but be reasonable.\n");
    }

    // In this loop you will determine how many spaces and bricks
    // are needed to print this line correctly, and do so.
    for (currentLine = 1; currentLine <= height; currentLine++)
    {

        int spacesTillBrick;
        int gapSpaces;
        spacesTillBrick = (height - currentLine);
        int bricksToPrint = (height - spacesTillBrick);

        for (int s = spacesTillBrick; s > 0; s--)
        {
            printSpace();
        }

        bricksToBePrinted(bricksToPrint);

        for (gapSpaces = 2; gapSpaces > 0; gapSpaces--)
        {
            printSpace();
        }

        bricksToBePrinted(bricksToPrint);
        printf("\n");
    }
    return 0;
}
