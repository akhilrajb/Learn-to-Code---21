//Write a C Program to read an integer and find it's square root.
#include <stdio.h>
#include <math.h>

int main() {
double number,sqroot;
    scanf("%lf", &number);
    sqroot = sqrt(number);
    printf("%.1lf",sqroot);
    return 0;
}
