//Write a C Program to display a calculator with a menu consisting of each operation to perform on the numbers using Switch Case statement.
#include<stdio.h>
int main()
{
    int num1,num2;
    int result1,result2,result3;
    int ch;   
    scanf("%d",&ch);
     
    scanf("%d",&num1);
    scanf("%d",&num2);
    
    printf("1.Addition");
    printf("\n2.Subtraction");
    printf("\n3.Multiplication");
    printf("\n4.Division");      
  
    
    switch(ch)    
    {
        case 1:
            result1=num1+num2;
            printf("\n%d",result1);
            break;
             
        case 2:
            result2=num1-num2;
             printf("\n%d",result2);
            break;
         
        case 3:
            result3=num1*num2;
            printf("\n%d",result3);
            break;
             
        case 4: if( num2 != 0)  
                  printf("\n%.1f",(num1/(float)num2));  
                  else  
                    printf("\nCannot be determined");  
                break;  
             
         default:
            printf("\nInvalid operation");
    }
 
     return 0;
}
