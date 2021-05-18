//WACP to determine if a triangle is valid from the given sides.
#include<stdio.h>
int main()
{
    int side1, side2, side3;
       scanf("%d%d%d", &side1, &side2, &side3);
       if(side1 + side2 > side3)
        {
      if(side2 + side3 > side1)
      {
      if(side1 + side3 > side2)
       {
        printf("Yes");    
     }
     else
     {
      printf("No");
     }              
     }
     else
     {
      printf("No");
     }  
         }
            else
         {
      printf("No");
     }  
     return 0;
 }
