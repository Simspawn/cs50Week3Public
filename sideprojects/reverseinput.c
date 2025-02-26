#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
// So far we can ask for take and repeat back string input.
// Next I need to write a for loop to reverse the array
int main(void)
{
    string word = get_string("Enter a word: \n");
    int count = 0, i = 0;
    for (i = 0; i < 50; i++)
    {
        if (word[i] != 0)
        count++;
    }
    printf("The word you said backwards is \"");
    for (i = count; i >= 0; i--)
        {
            printf("%c", word[i]);
        }
    printf(".\n");

return 0;
}
