#include <cs50.h>
#include <stdio.h>
// test result: scanf does not do what I want here. // Have since learned more about how scanf works.
int main()
{
    int num1[20];
    num1[0] = scanf("enter an int \n");
    printf("you entered %d \n", num1[0]);
return 0;
}
