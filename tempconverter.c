#include <cs50.h>
#include <stdio.h>
#include <string.h>

void printResult(float result)
{
    printf("The converted tempurature is: %f \n", result);
}

float convert(char conversion, float num1)
{

    float result = 0;
    if (conversion == 'c')
        return result = ((num1 * 9 / 5) + 32);
    else
        return result = ((num1 - 32) * 5 / 9);
}

char getConversionType()
{
    char conversion = get_char("Enter c to convert celsius to fahrenheit, f to convert fahrenheit "
                               "to celsius, or q to quit: \n");
    return conversion;
}

int main(void)
{
    char conversion = getConversionType();
    float num1 = get_int("Temp to convert: \n");
    float result = convert(conversion, num1);
    printResult(result);
    return 0;
}
