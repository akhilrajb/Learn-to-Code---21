//WACP to accept marks of three subjects.. Calculate the percentage and respective grade according
//to following: Percentage >= 90% : Grade A Percentage >= 80% : Grade B Percentage >= 70% : Grade C Percentage
//>= 60% : Grade D Percentage >= 40% : Grade E Percentage < 40% : Grade F
#include<stdio.h>
int main ()
{
    int mark1,mark2,mark3;
    float total,percentage;
    scanf("%d%d%d", &mark1,&mark2,&mark3);
    total= mark1+mark2+mark3;
    percentage = (total/300)*100;
    printf("%.2f ", percentage);
    if(percentage>=90) printf("\nA");
    else if(percentage>=80) printf("\nB");
    else if(percentage>=70) printf("\nC");
    else if(percentage>=60) printf("\nD");
    else if(percentage>=40) printf("\nE");
    else if(percentage<40)  printf("\nF");
        return 0;
}
