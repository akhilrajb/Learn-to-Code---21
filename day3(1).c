//Write a C Program to perform all four basic Mathematical Operations on two numbers taken from user input.
#include <stdio.h>

int main()
{
int a,b,sum,sub,mult;
    float division;
    scanf("%d %d", &a, &b);
    sum = a+b;
    printf("%d",sum);
    sub = a-b;
    printf("\n%d", sub);
    mult = a*b;
    printf("\n%d", mult);
    division = a/(float)b;
    printf("\n%.2f",division);
    
    return 0;
}
