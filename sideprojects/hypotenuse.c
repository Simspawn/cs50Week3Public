#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double side1, side2, side3;
    printf("Side one length: ");
    scanf("%lf", &side1);
    printf("Side two length: ");
    scanf("%lf", &side2);
    side3 = sqrt((side1 * side1) + (side2 * side2));
    printf("%lf\n", side3);
}
