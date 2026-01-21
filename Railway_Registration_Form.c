#include<stdio.h>
#include<string.h>

float total_amount(int,char gender[],int,char Class[],char payment_method[]);

void main()
{
	int age,distance;
	char gender[10],Class[10],payment_method[10];
	float ans;
	
	printf("This is Railway Registration Form:\n Please fulfill below questions:");
	
	printf("\n\nEnter your age here:");//Age
	scanf("%d",&age);
	
	printf("\nEnter your gender:\n(male / female):");//Gender
	scanf("%s",gender);
	
	printf("\nEnter the distance in km:");//Distance
	scanf("%d",&distance);
	
	printf("\nEnter the class here\n(Sleeper / 3AC / 2AC / 1AC):");//Class
	scanf("%s",Class);
	
	printf("\nEnter your payment method\n(UPI-Discount 10%% / Online-Discount 5%% / Cash-No Discount):");//Payment Method
	scanf("%s",payment_method);
	
	ans=total_amount(age,gender,distance,Class,payment_method);//Function Call
	printf("\n\nPayable ticket price=%f",ans);
	
}

float total_amount(int age,char gender[10],int distance,char Class[10],char payment_method[10])//Function definition
{
	float ans,dis1,dis2,dis3,surcharge,t_amount,total_amount;
	ans=distance*10;
	 
	//Age discount
	if(age<12)
	{
		dis1=ans*0.50;
		printf("\n\nDiscounts:\n Age < 12         -->50%%= %f\n",dis1);
	}
	else if(age>=60)
	{
		dis1=ans*0.40;
		printf("Age >= 60        -->40%%= %f\n",dis1);
	}
	else
	{
		dis1=0;
	}
	//Distance discount
	if(distance>500)
	{
		dis2=ans*0.10;
		printf(" \n\nDiscounts:\n Distance > 500   -->10%%= %f\n",dis2);
	}
	else if(distance>=101 && distance<=500)
	{
		dis2=ans*0.05;
		printf(" Distance 101-500 -->05%%= %f\n",dis2);
	}
	else
	{
		dis2=0;
	}
	
	
	//Payment discount
	char str1[5]="UPI",str2[10]="Online";
	if(strcmp(str1,payment_method)==0)
	{
		dis3=ans*0.10;
		printf(" UPI              -->10%%= %f\n",dis3);
		
	}
	else if(strcmp(str2,payment_method)==0) 
	{
		dis3=ans*0.05;
		printf(" Online           -->05%%= %f\n",dis3);
	}
	else
	{
		dis3=0;
	}
	
	t_amount=ans-(dis1+dis2+dis3);
	printf("\nTotal amount:%f",t_amount);
	
	//Class surcharge
	 char str3[5]="3AC",str4[5]="2AC",str5[5]="1AC";
	
	if(strcmp(str3,Class)==0) 
	{
		surcharge=t_amount*0.20;
		printf("\n\nSurchage:\n3AC  -->20%%= %f\n",surcharge);
	}
	else if(strcmp(str4,Class)==0)
	{
		surcharge=t_amount*0.30;
		printf("\n\nSurcharge:\n2AC  -->30%%= %f\n",surcharge);
	}
	else if(strcmp(str5,Class)==0)
	{
		surcharge=t_amount*0.40;
		printf("\n\nSurcharge:\n1AC  -->40%%= %f\n",surcharge);
	}
	else
	{
		surcharge=0;
	}
	total_amount=t_amount+surcharge;
	return total_amount;
	
}
