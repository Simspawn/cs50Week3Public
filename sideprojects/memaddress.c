#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 30;
    float gpa = 3.4;
    char grade = 'A';

    printf("%p %p %p\n", &age, &gpa, &grade);
}
