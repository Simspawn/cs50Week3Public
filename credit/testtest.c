#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 12, num2 = 123; long long num3 = 1234567890123456; // numb3 is 16 digits
    int num4 = num % 10, num5 = num2 % 10;
    long long num6 = num3 / 1000000000000000; // This has 15 0's, 16 total digits and leaves the first number
    long long num7 = num3 / 100000000000000; // This has 14 0's, 15 total digits and leaves the first 2 numbers
    printf("num4 = %i num5 = %i num6 = %lld num7 = %lld\n", num4, num5, num6, num7);
}
