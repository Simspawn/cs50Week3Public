#include <cs50.h>
#include <stdio.h>
void print_result(float z)
    {
        printf("%f\n", z);
    }

int main(void)
{
    printf("Enter two numbers to perform a calculation.\nEnter the first number, then enter the operator of the calculation you would like to perform. \nYou will then enter the second number.\n");

    float x = get_float("x: ");
    char calculation = get_char("Operation? + - * /\n");
    int operation = calculation;
    float y = get_float("y: ");
    float z;

    switch (operation)
        {

            case '/':
            if (y == 0)
            {
            printf("You know better than that.\n");
            break;
            }

            z = x / y;
            print_result(z);
            break;

            case '*':
            z = x * y;
            print_result(z);
            break;

            case '+':
            z = x + y;
            print_result(z);
            break;

            case '-':
            z = x - y;
            print_result(z);
            break;

            default: printf("You're doing it wrong.");
        }

return 0;
}
