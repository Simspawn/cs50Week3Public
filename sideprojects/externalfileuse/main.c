#include <stdio.h>
#include <stdlib.h>
#include "my_header.h"

int main()
{
    printf("Enter an int greater than 2: \n");
    int x = 2, userInput, if_int = scanf("%i", &userInput); //if_int == how many arguements were scanned in, &userInput
    printf("%i \n", userInput);                             // points what is scanned to that variable.
    bool valid = call_this_function(x, userInput);
    printf("%d %i \n", valid, userInput);
}
