#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch[10][130]={"Rajadhani Express[hyd-hnmk]==>>  11/7/22--starts at 10:00am","Garuda Express[hnmk-hyd]==>>  12/7/22--starts at 2:35pm","Venkateshwara Express[tirupati-hnmk]==>>  12/7/22--starts at 5:25am","Metro Express[adilabad-hyd]==>>  13/7/22--starts at 2:45pm","SR Express[nizambad-wgl]==>>  15/7/22--starts at 8:20am"};
char name[32][100]={'\0'};
char number[32][2]={'\0'};
int num1[32]={0};
int trno;
void bus();
void name_number(int booking,char numstr[100]);
void booking();
int read_number(int trno);
void read_name(int trno);
void status();
void status_1(int trno);
void cancle();

int main()
{
	login();
    int num,i;
    do{
    system("cls");
    printf("\n\n   ==================================================\n");
    printf("\t    BUS RESERVATION");
    printf("\n   ==================================================\n\n");
    printf("   ------------  MAIN MENU  ------------\n\n");
    printf("   [1] View Bus List\n\n");
    printf("   [2] Book Tickets\n\n");
    printf("   [3] Cancel Booking\n\n");
    printf("   [4] Bus Status Board\n\n");
    printf("   [5] Exit\n\n");
    printf("   ###################################################\n\n");
    printf("   ENTER YOUR CHOICE: ");
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        bus();
        break;
    case 2:
        booking();
        break;
    case 3:
        cancle();
        break;
    case 4:
        status();
        break;
    }
getch();
    }while(num != 5);
    system("CLS");
    printf("\n\n  ****************************************************\n");
    printf("   THANK YOU FOR USING THIS BUS RESERVATION SYSTEM");
    printf("\n   ==================================================\n");
    printf("   Visit Again\n");
    getch();
    return 0;
}


void bus()
{
    system("cls");
    printf("\n\n   ==================================================\n");
    printf("\t    BUS RESERVATION");
    printf("\n   ==================================================\n\n");
    printf("   ------------  BUS LIST  -----------\n\n");
    printf("   [1]  =>  %s\n\n",ch[0]);
    printf("   [2]  =>  %s\n\n",ch[1]);
	printf("   [3]  =>  %s\n\n",ch[2]);
	printf("   [4]  =>  %s\n\n",ch[3]);
	printf("   [5]  =>  %s\n\n",ch[4]);
}

void booking()
{

    int i=0;
    char numstr[100];
system("cls");
printf("\n\n   ==================================================\n");
printf("\t    BUS RESERVATION");
printf("\n   ==================================================\n\n");
bus();
printf("   ENTER THE BUS NUMBER: ");
scanf("%d",&trno);
system("cls");
printf("\n\n   ==================================================\n");
printf("\t    BUS RESERVATION");
printf("\n   ==================================================\n\n");printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
status_1(trno);
 FILE *f1, *fopen();
 char str1[80]="32",str2[4],str3[4];
 int seat1,seat2,booking=0;
if(trno == 1)
{
 f1 = fopen("tr1.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 2)
{
 f1 = fopen("tr2.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}else if(trno == 3)
{
 f1 = fopen("tr3.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","r+");
 fgets(str1,80,f1);
 fclose(f1);
}
seat1=atoi(str1);
if(seat1 <= 0)
{
 printf("There is no blank seat in this bus ");
}else
{
printf("\n   _____________________________________\n\n");
printf("Enter 0 to don't book tickets\n");
printf("\n   AVAILABLE SEATS: %d\n",seat1);
printf("\n   NUMBER OF TICKETS: ");
scanf("%d",&booking);
printf("\n");

seat1=seat1-booking;
itoa(trno,numstr,10);
name_number(booking,numstr);
printf("   The Total booking amount is %d",200*booking);
itoa(seat1, str1, 10);
if(trno == 1)
{
 f1 = fopen("tr1.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
else if(trno == 2)
{
 f1 = fopen("tr2.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 3)
{
 f1 = fopen("tr3.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 4)
{
 f1 = fopen("tr4.txt","w");
 fputs(str1,f1);
  fclose(f1);
}
else if(trno == 5)
{
 f1 = fopen("tr5.txt","w");
 fputs(str1,f1);
 fclose(f1);
}
}
}



void name_number(int booking,char numstr[100])
{
char tempstr[100],tempstr1[12]="status",tempstr2[12]="number";
int number;
    FILE *a,*b;
    int i=0;
   strcat(numstr,".txt");
   strcat(tempstr1,numstr);
   strcat(tempstr2,numstr);
   a = fopen(tempstr1,"a");
   b = fopen(tempstr2,"a");
for(i=0; i<booking; i++)
{
	  printf("\n  Select the seat which is not reserved.....\n");
      printf("   >>>>>>>>>>>> Enter the details for ticket no %d <<<<<<<<<<<<\n\n",i+1);
      printf("   ENTER THE SEAT NUMBER: ");
      scanf("%d",&number);
      printf("\n   ENTER THE PERSON NAME: ");
      scanf("%s",name[number-1]);
      printf("\n\n   +++++++++++++++++++++++++++++++++++++++++++++++++++\n");
      printf("\n");
      itoa(number, tempstr, 10);
      fprintf(a,"%s ",name[number-1]);
      fprintf(b,"%s ",tempstr);

}
fclose(a);
fclose(b);
}



int read_number(int trno)
{
char tempstr[100],tempstr2[12]="number";
FILE *a,*b;
char numstr[100];
int i=0,j=0,k;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr2,numstr);
a = fopen(tempstr2,"a+");
   while(!feof(a))
   {
      number[i][j] = fgetc(a);

      if(number[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
      j++;
      }
   }
   k=i;
   for(i=0; i<k; i++)
   {
       num1[i] = atoi(number[i]);
   }
   fclose(a);
   return k;
}


void read_name(int trno)
{
char tempstr1[12]="status";
FILE *b;
char numstr[100];
int i=0,j=0,k=0;
itoa(trno,numstr,10);
strcat(numstr,".txt");
strcat(tempstr1,numstr);
b = fopen(tempstr1,"a+");
   while(!feof(b))
   {
      name[i][j] = fgetc(b);

      if(name[i][j] == ' ')
      {
          j=0;
          i++;
      }
      else
      {
        j++;
      }

   }
   name[i][j]='\0';
   k=i;
   fclose(b);
}

void status()
{
system("cls");
    printf("\n\n   ==================================================\n");
    printf("\t    BUS RESERVATION");
    printf("\n   ==================================================\n\n");
    int i,trno,index=0,j;
    printf("   ENTER THE BUS NUMBER: ");
    scanf("%d",&trno);
    j=read_number(trno);
    read_name(trno);
    printf("\n   ==================================================\n");
    printf("\t\t   Bus No.%d: %s\n",trno,ch[trno-1]);
    printf("   =================================================\n\n");
    char tempname[33][10]={"-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
    }
}

void status_1(int trno)
{
    printf("Your Bus Number is %d ********** %s",trno,ch[trno-1]);
    system("cls");
    printf("\n   =================================================================\n");
    printf("\t\t   Bus No.%d: %s\n",trno,ch[trno-1]);
    printf("   =================================================================\n\n"); 
    int i,index=0,j;
    j=read_number(trno);
    read_name(trno);
    char tempname[33][10]={"-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t ","-\t "};
    for(i=0; i<j; i++)
    {
        strcpy(tempname[num1[i]],name[i]);
    }
    for(i=0; i<8; i++)
    {
        printf("   ");
        for(j=0; j<4; j++)
            {
        printf("%d.%s\t",index+1,tempname[index+1]);
        index++;
            }
            printf("\n");
}
}


void cancle()
{
 int seat_no,i,j;
 char numstr[100],tempstr2[15]="number",tempstr1[15]="status";
 printf("\n   ENTER THE BUS NUMBER: ");
 scanf("%d",&trno);
 itoa(trno,numstr,10);
 strcat(numstr,".txt");
 strcat(tempstr1,numstr);
 strcat(tempstr2,numstr);
 read_number(trno);
 read_name(trno);
 status_1(trno);
 printf("\n\n   ==================================================\n");
 printf("\n  Select the tickect that you booked \n\n ");
 printf("   ENTER THE SEAT NUMBER: ");
 scanf("%d",&seat_no);
 FILE *a,*b;
 a = fopen(tempstr1,"w+");
 b = fopen(tempstr2,"w+");
 for(i=0; i<32; i++)
 {
     if(num1[i] == seat_no)
     {
         for(j=0; j<32; j++)
         {
             if(num1[j] != seat_no && num1[j] != 0)
             {
                 fprintf(b,"%d ",num1[j]);
                 fprintf(a,"%s",name[j]);
             }
             else if(num1[j] == seat_no && num1[j] != 0)
             {
                 strcpy(name[j],"Empty ");
             }
         }
     }
 }
fclose(a);
fclose(b);
printf("\n\n");
    printf("\n\n   ===============================================\n");
 printf("   Your 200 rupees has been Returned\n");
    printf("   ===============================================\n");
}


void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="user";
    do
{
	system("cls");
    printf("\n\n   ==================================================\n");
    printf("\t    BUS RESERVATION");
    printf("\n   ==================================================\n\n");
    printf("   ~~~~~~~~~~~~  LOGIN FORM  ~~~~~~~~~~~~  ");
    printf("\n\n   ENTER USERNAME: ");
	scanf("%s", &uname);
	printf(" \n   ENTER PASSWORD: ");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	
	i=0;
	
		if(strcmp(uname,"user")==0 && strcmp(pword,"user")==0)
	{
    printf("\n   ***************************************");
	printf("  \n\n   WELCOME USER !!!!");
	printf("\n\n\n   Press any key to continue...");
	getch();
	break;
	}
	else
	{
	    printf("\n   -----------------------------------------------------");
		printf("\n\n   LOGIN IS UNSUCESSFUL...PLEASE TRY AGAIN...");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}
