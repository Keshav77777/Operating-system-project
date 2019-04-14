#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<conio.h>
#include<windows.h>

int n=0,option=-1;

void gotoxy(long x, long y) 
      {
           COORD pos = {x, y};
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
      }
/////////////////////////////////////

struct Process
{
	int P_ID,arivl_tym,burst_tym,original_burst_tym,completion_tym,waiting_tym,turnaround_tym,flag;
};

////////////////////////
average(struct Process P[n])
{
	int i;
	float totWt=0,totTt=0,avgWt,avgTt;
	for(i=0;i<n;i++)
	{
		totWt+=P[i].waiting_tym;
		totTt+=P[i].turnaround_tym;
	}
	avgWt=totWt/n;
	avgTt=totTt/n;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		gotoxy(71,2*n+12);	
		printf("%c     %.2f ",179,avgWt);
		gotoxy(86,2*n+12);	
		printf("%c    %.2f",179,avgTt);
}
///////////////////////////////////////////////////////////////////////////////////////
  
void frame()
{
	
	int i;
	
	for(i=0;i<91;i++)
	{
		gotoxy(11+i,3);
		printf("=");
		gotoxy(11+i,6);
		printf("_");
		gotoxy(11+i,2*n+7);
		printf("%c",175);
		if(i<30)
		{
		gotoxy(71+i,2*n+8);
		printf("=");
		gotoxy(71,2*n+9);
		printf("%c   Average    %c",179,179);
		gotoxy(71,2*n+10);	
		printf("%c     W.T      %c",179,179);
		gotoxy(89,2*n+9);
		printf("Average    %c",179,179);
		gotoxy(89,2*n+10);	
		printf("  T.T      %c",179,179);
		gotoxy(71+i,2*n+11);
		printf("%c",175);
		gotoxy(71+i,2*n+13);
		printf("%c",175);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		gotoxy(71,2*n+12);	
		printf("%c       .      %c",179,179);
		gotoxy(89,2*n+12);	
		printf("    .      %c",179);
		
	    }
	}
	////////////////
	gotoxy(15,4);
    printf("Process    %c",179);
    gotoxy(15,5);
    printf("  ID       %c",179);
    gotoxy(30,4);
    printf("arivl    %c",179);
    gotoxy(30,5);
    printf(" tym      %c",179);
    gotoxy(45,4);
    printf("Burst      %c",179);
    gotoxy(45,5);
    printf("tym       %c",179);
    gotoxy(60,4);
    printf("Completion %c",179);
    gotoxy(60,5);
    printf("   tym    %c",179);
    gotoxy(75,4);
    printf("Waiting    %c",179);
    gotoxy(75,5);
    printf(" tym      %c",179);
    gotoxy(89,4);
    printf("TurnAround %c",179);
    gotoxy(89,5);
    printf("   tym    %c",179);
	////////////////
    for(i=0;i<n*2+4;i++)
	{
		gotoxy(11,i+4);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
		//printf("%c",179);
		printf("%c",179);
		printf("%c",222);
		
		gotoxy(100,i+4);
		printf("%c",222);
		printf("%c",179);
		//printf("||");
	}
}
/////////////////////////////////////////////////////////////////////////////
void display(struct Process P[n])
{
	//frame();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
	int i,l=0,b=0;
	//n=7;
	for(i=0;i<n;i++)
    {
    l+=2;
	  //gotoxy(12,5+i);
	gotoxy(15,6+l);
	if(P[i].P_ID==-1)
    printf("   %c       %c",249,179);
    else
    {
    printf("           %c",179);
    gotoxy(15,6+l);
    printf("   P%d",P[i].P_ID);
    }
    
    gotoxy(30,6+l);
    if(P[i].arivl_tym==-1)
    printf("   %c       %c",249,179);
    else{
    printf("           %c",179);
    gotoxy(30,6+l);
    printf("   %d",P[i].arivl_tym);
    }
    gotoxy(45,6+l);
    if(P[i].burst_tym==-1)
    printf("   %c       %c",249,179);
    else{
    printf("           %c",179);
    gotoxy(45,6+l);
    printf("   %d",P[i].original_burst_tym);
    }
    gotoxy(60,6+l);
    if(P[i].completion_tym==-1)
    printf("   %c       %c",249,179);
    else{
    printf("           %c",179);
    gotoxy(60,6+l);
    printf("   %d",P[i].completion_tym);
    }
    gotoxy(75,6+l);
    if(P[i].waiting_tym==-1)
    printf("   %c       %c",249,179);
    else{
    printf("           %c",179);
    gotoxy(75,6+l);
    printf("   %d",P[i].waiting_tym);
    }
    gotoxy(89,6+l);
    if(P[i].turnaround_tym==-1)
    printf("   %c       ",249);
    else{
    printf("           %c",179);
    gotoxy(89,6+l);
    printf("   %d",P[i].turnaround_tym);
    }
    int j;
    for(j=0;j<87;j++)
    {
    gotoxy(13+j,6+l+1);
    if(j%15==13)
    printf("%c",206);
    else
    printf("=");
	}
	}
	frame();
	
}
///////////////////////////////////////////////////////////////////////////////
////////////////////
int main()
{
	int i,j,l=0,burst_count=0;
	printf("Enter the number of process to enter\n");
	scanf("%d",&n);
	system("cls");
	struct Process P[n];
	
	for(i=0;i<n;i++)
    {
    	P[i].arivl_tym=-1,P[i].burst_tym=-1,P[i].completion_tym=-1,P[i].P_ID=-1;
    	P[i].turnaround_tym=-1,P[i].waiting_tym=-1;
	}
	
	for(i=0;i<n;i++)
    {
    	l+=2;
    	display(P);
    	gotoxy(33,2*n+10);
    	printf("Enter arivl tym for process %d\n",i+1);
    	P[i].P_ID=i+1;
    	P[i].flag=0;
    	gotoxy(33,6+l);
	    scanf("%d",&P[i].arivl_tym);
	    
	    gotoxy(33,2*n+10);
	    printf("Enter burst tym for process %d\n",i+1);
    	gotoxy(48,6+l);
	    scanf("%d",&P[i].burst_tym);
	    
	    //P[i].burst_tym=2*P[i].arivl_tym;
	    burst_count+=P[i].burst_tym;
	    P[i].original_burst_tym=P[i].burst_tym;
	}
	
	gotoxy(33,2*n+10);
	    printf("                                   ");
	
	//sorting according to arivl_tym
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-j-1;i++)
		{
			if(P[i].arivl_tym>P[i+1].arivl_tym)
			{	
			struct Process t=P[i];
			P[i]=P[i+1];
			P[i+1]=t;
         	}
	    }
	}
	
	int tym_t,count_n=0,temp_i=0,prev_temp_i=-3,temp_opt=-1,v=0;
	
	//main algorithm
	if(P[0].arivl_tym>3)
	{
		tym_t=P[0].arivl_tym;
	}
	else tym_t=3;
	int totl_tym=tym_t;
	
	do
	{
		int min=99999,x=0;
		temp_opt=min;
		
		for(i=0;P[i].arivl_tym<=tym_t && i<n;i++)
		{
	            if(P[i].burst_tym<=temp_opt &&P[i].flag==0)
	        	{
	        		x=1;
	        		temp_opt=P[i].burst_tym;
	        		temp_i=i;
	            }
        }
        
        //if(P[i].burst_tym<=temp_opt &&P[i].flag==0)
	        	{
	        		//printf("don");
	        		if(P[temp_i].burst_tym<=0)
	        		{
	        		temp_opt=0;
	        		P[temp_i].burst_tym=0;
	        	    }
	        	    
	        	    else
	        		if(P[temp_i].burst_tym<=10)
	        		{
	        		temp_opt=P[temp_i].burst_tym;
	        		totl_tym+=temp_opt;
	        		P[temp_i].burst_tym=0;
	        	    }
	        	    
	        		else
	        		{
	        		temp_opt=10;
	        		P[temp_i].burst_tym-=10;
	        		totl_tym+=10;
	        		printf("aaaaaaa");
	        		getch();
	        	    } 
	            }

        if(x==0)
        {
        	printf("if Inside if \n");
	     	getch();
            //printf("hello");
            tym_t+=1;
            totl_tym+=1;
		}
		
		else
		{	
		printf("Inside else \n");
		getch();
        printf("\n");
        if(P[temp_i].burst_tym==0 && P[temp_i].flag==0)
        {
    	printf("Inside double \n");
		getch();
        P[temp_i].completion_tym=totl_tym;//tym_t+temp_opt;
        P[temp_i].turnaround_tym=P[temp_i].completion_tym-P[temp_i].arivl_tym;
        P[temp_i].waiting_tym=P[temp_i].turnaround_tym-P[temp_i].original_burst_tym;
        P[temp_i].flag=555;
       // printf("\n\n\n\n ddf sxs");
        //getch(); 
        }
        display(P);
        getch();
        //printf("\n\n\n\nddfelse");
        //getch();
        //if(P[temp_i].burst_tym<=10)
        tym_t+=temp_opt;
        burst_count-=temp_opt;	
        }
        
        prev_temp_i=temp_i;
        if(burst_count==0)
        average(P);
        
	}while(burst_count>0);
}
