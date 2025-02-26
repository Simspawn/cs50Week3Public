#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fpointer = fopen("test.txt", "w");  //r w a read write appened
    fprintf(fpointer, "This is a test.  \nIt was a success. \nIs it still a succes?");
    printf("yes it was \n");
    fclose(fpointer);
return 0;
}
