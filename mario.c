#include <cs50.h>
#include <stdio.h>

int main(void)
{
        // Prompt user for positive int
        int n;
        do
        {
                n = get_int("Size; ");
        }
        while (n < 1);

        // Print n-by-n grid of blocks
        for (int i = 0; i < n; i++)
        {
                for (int j = 0; j < n; j++)
                {
                        printf("#");
                }
                printf("\n");
        }
}
