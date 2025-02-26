#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int digits[100] = {0}, toBeAdded[100] = {0}, toBeAdded2[100] = {0}, isValid = 0, validInput = 0,
        counter = 0, first2 = 0, sum1 = 0, sum2 = 0, i = 0, x = 0, y = 0, xy = 0;
    long long cCNum = 0, count = 0;

    printf("Enter a credit card number with no spaces: \n");
    isValid = scanf("%lld", &cCNum), count = cCNum;
    while (count >= 1)
    {
        count /= 10;
        counter++;
    }
    count = cCNum; // reset to cCnum to continue working with the value without losing the data.
    for (i = counter; i > 0; i--) // Seperates and reverses the digits.
    {
        digits[x] = count % 10;
        count /= 10;
        x++;
    }
    x = 1;
    for (i = 1; i <= counter;
         i++) // Checksum, multiply every other number by 2 and seperate the digits.
    {
        if (digits[x] < 5)
        {
            toBeAdded[y] = (digits[x] * 2);
        } else
            {
                toBeAdded[y] = ((digits[x] * 2) - 10);
                y++;
                toBeAdded[y] = 1;
                xy++;
            }
        x++, x++, y++;
    }
    for (i = 0; i <= (counter + xy); i++)
    {
        sum2 += toBeAdded[i];
    }
    x = 0;
    for (i = 0; i < counter; i++)
    {
        sum1 += digits[x];
        x++, x++;
    }
    if (((sum1 + sum2) % 10) == 0)
    {
        switch (counter)
        {
            case 13:
                if (digits[12] == 4)
                {
                    printf("VISA\n");
                }
                else
                    printf("INVALID\n");
                break;
            case 15:
                first2 = cCNum / 10000000000000;
                if (first2 == 34 || first2 == 37)
                {
                    printf("AMEX\n");
                }
                else
                    printf("INVALID\n");
                break;
            case 16:
                first2 = cCNum / 100000000000000;
                if (digits[15] == 4)
                {
                    printf("VISA\n");
                }
                else if (first2 > 50 && first2 < 56)
                {
                    printf("MASTERCARD\n");
                } else
                    printf("INVALID\n");
                break;
            default:
                printf("INVALID\n");
                break;
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
