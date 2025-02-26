#include <stdio.h>

int main(void)
{
    char str1[6] = ("Hello");
    char c0 = str1[0];
    char c1 = str1[1];
    char c2 = str1[2];
    char c3 = str1[3];
    char c4 = str1[4];
    char str2[6]; str2[0] = c4; str2[1] = c3; str2[2] = c2; str2[3] = c1; str2[4] = c0; str2[5] = 0;
    printf("%s\n", str2);
}



