#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my_header.h"

bool call_this_function(int x, int userInput)
{
    if (userInput < x)
    {
        printf("lesser than 2 \n");
        return false;
    } else
        {
            printf("greater than 2 \n");
            return true;
        }
}
