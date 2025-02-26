#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long num = 1234567890123;
    long long count = num;
    //int digit13 = (count % 10);     // Last digit.
    //int digit12 = ((count % 100 - digit13) / 10); // Next to last digit.
    //int digit11 = ((count % 1000 - digit12) / 100);
    //int digit10 = ((count % 10000 - digit11) / 1000); //
    //int digit9 = ((count % 100000 - digit10) / 10000);
    //int digit8 = ((count % 1000000 - digit9) / 100000); //
    //int digit7 = ((count % 10000000 - digit8) / 1000000);
    //int digit6 = ((count % 100000000 - digit7) / 10000000 ); //
    //int digit5 = ((count % 1000000000 - digit6) / 100000000);
    //int digit4 = ((count % 10000000000 - digit5) / 1000000000); //
    //int digit3 = ((count % 100000000000 - digit4) / 10000000000);
    //int digit2 = ((count % 1000000000000 - digit3) / 100000000000);//
    //int digit1 = ((count % 10000000000000 - digit2) / 1000000000000);



    // Seperates the digits
    int digits[20];
    int x = 0;
    for (int i = 13; i > 0; i--)
    {
        digits[x] = count % 10;
        count /= 10;
        x++;
    }

    // Prints the seperate digits.
    x = 0;
    for (int i = 13; i > 0; i--)
    {

        printf("%i ", digits[x]);
        x++;
    }
    printf("\n");
    //printf("%i %i %i %i %i %i %i %i %i %i %i %i %i \n", );

    // Step one, multiply every other number by 2, starting with the next to last digit.
    //int stpOneInt1 = (), stpOneInt2 = (), stpOneInt3 = (), stpOneInt4 = (), stpOneInt5 = (), stpOneInt6 = ();

    // Step two, add the individual digits which were multiplied by 2.
    //int stpTwoInt1 = (stpOneInt1 - 10), stpTwoInt2 = (stpOneInt1 % 10);


 // can i just make functions for each step? How would I even implement that? I still need to get checksum to actually work.
}
