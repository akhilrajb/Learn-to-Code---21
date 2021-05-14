//Write a C Program to find the maximum and minimum from three user inputted numbers.
#include <stdio.h>

int main()
{
    
    int n1, n2, n3, maximum, minimum;
    scanf("%d %d %d", &n1,&n2,&n3);   
    minimum = n1;
    maximum = n2;
    if (n3 > maximum)
    {
        maximum = n3;
    }
    if (n1 > maximum)
    {
        maximum = n1;
    }
    if (n2 < minimum)
    {
       minimum = n2;
    }
    if (n3 < minimum)
    {
       minimum = n3;
    }
    printf("%d", maximum);
    printf("\n%d", minimum);
    return 0;
}
