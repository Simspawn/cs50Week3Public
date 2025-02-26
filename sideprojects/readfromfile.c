#include <stdio.h>
#include <stdlib.h>

int main()
{
    char line[255];
    FILE * fpointer = fopen("test.txt", "r");

    fgets(line, 255, fpointer); // According to freecodecamp fgets is going to increment (++) the fpointer and doing so will allow us to access each next line of text.
    printf("%s \n", line);
    fgets(line, 255, fpointer); // This reads and sets line == to the second line of text in test.txt.
    printf("%s \n", line);

    fclose (fpointer);
return 0;
}
