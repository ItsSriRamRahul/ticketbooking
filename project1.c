#include<stdio.h>
FILE *fp,*nfp; 

int flag=0;
char movies[25][10];
void book(void);
void refund(void);
struct movies{
	char name[25];
	int price;
	int seats;
};
struct movies Mov[5];

void main(){
	int ch;
	printf("welcome to ticket booking system please select sno.\n");
	while(1){
		printf("1:book\n2:refund\n3:exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: book();
			break;
			case 2: refund();
			break;
			case 3: printf("Thank you visit again");
					exit(0);
					break;
			default:printf("invailid input\n");
					break;
		}
	}
}
void book(){
	    flag=1;
		fp=fopen("booking.txt","r+");
	int i=0,j=0;
	int ch,count=0;
	char c;
	
		while(!feof(fp)){
			fscanf(fp,"%s %d %d ",&Mov[i].name,&Mov[i].price,&Mov[i].seats );
			printf("%d: movie-->%s price-->%d seats-->%d\n \n",i+1,Mov[i].name,Mov[i].price,Mov[i].seats);
			i++;
		}
		
		printf("choose movie input serial number\n");
		scanf("%d",&ch);
		printf("%s Booked!\n",Mov[ch-1].name);
		
		
		Mov[ch-1].seats--;
		fseek(fp,0,0);
		while(!feof(fp)){
				
		fprintf(fp,"%s %d %d\n",Mov[j].name,Mov[j].price,Mov[j].seats);
		j++;
		if(j==5){
			break;
		}
	}
		
		
		
fclose(fp);
}
void refund(){
if(flag){fp=fopen("booking.txt","r+");
int i,ch,j=0;

printf("which movie you would like to refund from these enter serial number\n");
for(i=0;i<5;i++){
	printf("%d :%s\n",i+1,Mov[i].name);
}
scanf("%d",&ch);
Mov[ch-1].seats++;
printf("%s refunded!\n ",Mov[ch-1].name);
	fseek(fp,0,0);
		while(!feof(fp)){
				
		fprintf(fp,"%s %d %d\n",Mov[j].name,Mov[j].price,Mov[j].seats);
		j++;
		if(j==5){
			break;
		}
	}
	fclose(fp);
}
	else{
		printf("nothing to refund\n");
	}
}
