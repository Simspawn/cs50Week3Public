#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age = 30;
    int * p_age = &age;
    float gpa = 3.4;
    float * p_gpa = &gpa;
    char grade = 'A';
    char * p_grade = &grade;

                                // When creating pointers, you are storing the memory address of a variable which already exists.

    printf("age's memory address: %p\n", &age); //Prints the memory address of age. the &age is the pointer our %p is given.

    printf("gpa's memory address is: %p\n", p_gpa); //Prints the memory address of gpa. p_gpa is the pointer variable we created to store the memory address of gpa.

return 0;
}
