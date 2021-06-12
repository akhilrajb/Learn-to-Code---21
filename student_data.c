// This project done by Akhil Raj B,S2 EEE (E Batch)  as a part of HackerRank C programming Course
// Conducted by IEEE Computer Society Student Branch Chapter College of Engineering Chengannur.
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

void addnew();
void display();
void search();
void update();
void delete();
void mainmenu();

// structure declaration with structure point s

struct student
{
    char name[25];
    char mobile[20];
    char regno[25];
    char course[20];
    char batch[20];
}s;


void mainmenu()
{
    int option;
    system("cls");
      
    printf("\n\n\t:: STUDENT DATA MANAGEMENT SYSTEM ::");
   
    printf("\n\t====================================");
   
    printf("\n\t::         MAIN MENU              ::");
    
    printf("\n\t====================================");
   
    printf("\n\n\t1 >> Add New  Record");
   
    printf("\n\t2 >> Display  Record");
   
    printf("\n\t3 >> Search A Record");
   
    printf("\n\t4 >> Update A Record");
    
    printf("\n\t5 >> Delete A Record");
     
    printf("\n\t6 >> Exit");
      
    printf("\n\n\t====================================");
    printf("\n\n\tChoose your option >> ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:
        addnew();
        break;

    case 2:
        display();
        break;

    case 3:
        search();
        break;

    case 4:
        update();
        break;

    case 5:
        delete();
        break;

    case 6:
        exit(0);
        break;

    default:
    
	   printf("\n\tSorry,Wrong Option");
       Sleep(1000);
       exit(0);
    }
}
//ADD NEW RECORD
void addnew()
{
    FILE *fp;
    FILE *fp1;
    char dummyregno[25]; 
    char repeat ='y';
    system("cls");
    fp = fopen("student.txt","ab+");
    if(fp == NULL)
	{
        printf("Error");
        exit(1);
    }
    fflush(stdin);
    printf("\n\n\n\tADD NEW RECORD");
    printf("\n\n\tEnter student Details");
   
    while(repeat == 'y')
     {
        printf("\n\n\tEnter Register No : ");
        gets(dummyregno);
        
// Validation 
       
        while(fread(&s,sizeof(s),1,fp ) == 1)
  	    {
        if(strcmp(dummyregno,s.regno) == 0)
	    {
          printf("\n\n\tAlert! Register Number Already Exists");
          printf("\n\n\tTry Again");
          Sleep(1500);
          fclose(fp);
          mainmenu();}
         }  
   
         if (!*dummyregno)
       
 	    {
          printf("\n\n\tAlert! You Must Enter Register Number");
          printf("\n\n\tTry Again");
          Sleep(1500);
          fclose(fp);
          mainmenu();
            }
// Storing Details
      		
		else
         {
	    strcpy(s.regno,dummyregno);
        printf("\n\tEnter Name : ");
        gets(s.name);
        printf("\n\tEnter Mobile Number : ");
        gets(s.mobile);
        printf("\n\tEnter Course : ");
        gets(s.course);
        printf("\n\tEnter Batch : ");
        gets(s.batch);
        fwrite(&s,sizeof(s),1,fp);
        repeat = 'n';
                   
    }}
   
    fclose(fp);
    printf("\n\n\tPress any key to continue.");
    getch();
    mainmenu();
}

// Display Students Details

void display()
{
    FILE *fp;
    int i=1,j;
    system("cls");
    printf("\n\n\n\tDISPLAY STUDENT DETAILS");
    printf("\n\t----------------------------------------------------------------------------------");
    printf("\n\tS.No  Register No   Name of Student         Mobile No        Course      Batch");
    printf("\n\t----------------------------------------------------------------------------------");
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
               printf("No record found");
     }
    j=8;
    while(fread(&s,sizeof(s),1,fp) == 1){
        //printf("\n\t%-7d%-13s%-22s%-16s%-12s%-10s",i,s.regno,s.name,s.mobile,s.course,s.batch);
          printf("\n\t%-6d%-14s%-24s%-17s%-12s%-10s",i,s.regno,s.name,s.mobile,s.course,s.batch);
        i++;
        j++;
    }
    fclose(fp);
    printf("\n\t----------------------------------------------------------------------------------");
    printf("\n\n\n\tPress any key to continue.");
    getch();
    mainmenu();
}

// Search Students Details

void search()
{
    FILE *fp;
    char dummyregno1[20];
    system("cls");
    printf("\n\n\n\tSEARCH STUDENT DETAILS");
    printf("\n\n\tEnter register number : ");
    fflush(stdin);
    gets(dummyregno1);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("\n\tError");
        exit(1);
    }
    while(fread(&s,sizeof(s),1,fp ) == 1){
        if(strcmp(dummyregno1,s.regno) == 0)
		{
            
            printf("\n\tRegister No   : %s",s.regno);
            printf("\n\tName          : %s",s.name);
            printf("\n\tMobile Number : %s",s.mobile);
            printf("\n\tCourse        : %s",s.course);
            printf("\n\tBatch         : %s",s.batch);
        }
    }
    fclose(fp);
    printf("\n\n\tPress any key to continue.");
    getch();
    mainmenu();
}

// Update Students Details

void update()
{
    char dummyregno2[20];
    long int recsize;
    FILE *fp;
    recsize = sizeof(s);
    system("cls");
    printf("\n\n\n\tUPDATE STUDENT RECORD");
    printf("\n\n\tEnter register number: ");
    fflush(stdin);
    gets(dummyregno2);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
         printf("\n\tError");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&s,sizeof(s),1,fp) == 1)
    {
        if(strcmp(dummyregno2,s.regno) == 0)
		{
     
		    strcpy(s.regno,dummyregno2);  
		    printf("\n\tEnter name: ");
            gets(s.name);
            printf("\n\tEnter mobile number : ");
            gets(s.mobile);
            printf("\n\tEnter Course : ");
            fflush(stdin);
            gets(s.course);
            printf("\n\tEnter Batch : ");
            gets(s.batch);
            fflush(stdin);
            fseek(fp,-recsize,SEEK_CUR);
            fwrite(&s,recsize,1,fp); 
            break;
        }
        
     }
      
    fclose(fp);
    printf("\n\n\tPress any key to continue.");
    getch();
    mainmenu();
}

//Delete Students Details

void delete()
{
    char dummyregno3[20];
    FILE *fp,*ft;
    system("cls");
    printf("\n\n\n\tDELETE STUDENT RECORD");
    printf("\n\n\tEnter register number : ");
    fflush(stdin);
    gets(dummyregno3);
    fp = fopen("student.txt","rb+");
    if(fp == NULL){
        printf("\n\tError");
        exit(1);
    }
    ft = fopen("dummy.txt","wb+");
    if(ft == NULL){
        printf("Error");
        exit(1);
    }
    while(fread(&s,sizeof(s),1,fp) == 1){
        if(strcmp(dummyregno3,s.regno)!=0)
            fwrite(&s,sizeof(s),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("student.txt");
    rename("dummy.txt","student.txt");
    printf("\n\tPress any key to continue.");
    getch();
    mainmenu();
}


int main()
{
    mainmenu();
    return 0; 
}