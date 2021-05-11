//Write a C Program to perform Read and Print operations using the four basic data types in C. (int, float, char & double)
#include <stdio.h>

int main()
{
    char a;
    int b;
    float c;
    double d;
    scanf("%c",&a);
    printf("%c",a);
    printf("\n");
    scanf("%d",&b);
    printf("%d",b);
    printf("\n");
    scanf("%f",&c);
    printf("%f",c);
    printf("\n");  
    scanf("%lf",&d);
    printf("%lf",d);
    
    return 0;
}
