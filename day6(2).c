//Write a C Program to determine the factorial of a number.
#include <stdio.h>
int main()
{
   int i,fact=1,number;    
   scanf("%d", &number);
   if (number < 0)
        printf("ERROR");
     else 
     {
     for(i=1;i<=number;i++){    
      fact=fact*i;    
        }    
  printf("%d",fact);   
     }
    return 0;
}
