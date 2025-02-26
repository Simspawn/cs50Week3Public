#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
    {
        char name[50];
        char major[50];
        int age;
        float gpa;
    };

struct Point
{
    int x, y;
};

int main()
{
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");
    strcpy(student1.major, "Business");

    struct Student student2;
    student2.age = 22;
    student2.gpa = 3.2;
    strcpy(student2.name, "Pam");
    strcpy(student2.major, "Art");

    printf("%s \n", student2.name);

    struct Point path[] = {{0, 1}, {2, 2}, {23, 3}};
    for (int i =0; i < 3; i++)
    {
        printf("%i, %i \n", path[i].x, path[i].y);
    }


return 0;
}
