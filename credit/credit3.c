#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int toBeAdded[16], toBeAdded2[8], validInput = 0, addedProds = 0, adds = 0;
    long long cCNum = 0;
//while (validInput == 0)
//    {
        printf("Enter a credit card number with no spaces: \n");
        int counter = 0, isValid = scanf("%lld", &cCNum);
        long long count = cCNum;
        while (count >= 1)
            {
                count /= 10;
                counter++;
            }
        // Seperate the digits.
        count = cCNum;
        int digits[counter], x = 0;
        for (int i = counter; i > 0; i--)
            {
                digits[x] = count % 10;
                count /= 10;
                x++;
            }
        // Prints the seperate digits.
        x = 0;
        for (int i = counter; i > 0; i--)
            {
                printf("This is digits[%i] ", digits[x]);
                x++;
            }
        // Checksum
        x = 1;
        int y = 0;
        for (int i = 1; i < (counter / 2); i++)
            {
                if (digits[x] < 5)
                    {
                        toBeAdded[y] = (digits[x] * 2);
                        y++;
                    } else
                        {
                            toBeAdded[y] = ((digits[x] * 2) - 10);
                            y++;
                            toBeAdded[y] = 1;
                            y++;
                        }
                if (x < 7)
                    {
                        x += 2;
                    }
            }

        x = 0, y = 1;
        for (int i = 0; i < 17; i++)
            {
                addedProds = (toBeAdded[x] + toBeAdded[y]);
                x++, y++;
            }

        printf("\n");
        y = 0;
        for (int i = counter; i > 0; i--)
            {
                printf("This is toBeAdded[%i] ", toBeAdded[y]);
                y++;
            }
        printf("%i This is Prods \n", addedProds);
//    }
}

