#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nums[2][5] =                                // 2 being how many elements are in the array of arrays 5 being how many elements is each array
    {
        {3, 2, 1, 5, 4},
        {4, 3, 3, 6, 7}
    };

    printf("%i \n", nums[1][3]);                    // Prints the 6


                                                    // In this for loop each element of the array of arrays is printed.
    int i, j;
    for(i = 0; i < 2; i++)                          // 2 being how many elements are in the array of arrays
        {
            for(j = 0; j < 5; j++)                  // 5 being how many elements is each array
                {
                    printf("%i ", nums[i][j]);
                }
            printf("\n");
        }
}
