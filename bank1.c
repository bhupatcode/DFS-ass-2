/*Bank Program */
               /* BCA Bank */
#include<stdio.h>
#include<stdlib.h>/*Malloc header file*/

struct bank
{
	int accno;
	char name[100];
	int bal;
	struct bank *next,*pre;
}*newacc,*temp,*first=0,*last=0;

int n=0;

int cacc();/*Create Account*/
int	deposit();/*Deposit Amount*/
int	withdraw();/*Withdraw Amount*/
int	checkbal();/*Check Balance in account*/
int checkacc();/*Check all acount in the bank*/
int deacc();/*Delete the account*/

int main()
{
	int ch;
	
	
	printf("1.Create Accout\n");
	printf("2.Deposit\n");
	printf("3.Withdraw\n");
	printf("4.Check Balance\n");
	printf("5.Check Account\n");
	printf("6.Delete Account\n");
	printf("7.Exit\n");
	printf("Choose=");
	scanf("%d",&ch);
	
	system("cls");
	switch(ch)
	{
		case 1:
			cacc();
			main();
			
		case 2:
			deposit();
			main();
			
		case 3:
			withdraw();
			main();
			
		case 4:
			checkbal();
			main();
			
		case 5:
			checkacc();
			main();
		
		case 6:
			deacc();
			main();
			
		case 7:
			exit(0);
			
		default:
			printf("Invalid choice");
			getch();
			main();
	}
	
	getch();
}

int cacc()/*Create Account*/
{
	newacc=(struct bank *)malloc(sizeof(struct bank));
	
	printf("Account No=%d\n",n+1);
	newacc->accno=n+1;
	printf("Account Holder Name=");
	scanf("%s",&newacc->name);
	printf("Balance=5000\n");
	newacc->bal=5000;
	newacc->pre=0;
	newacc->next=0;
	
	if(first==0)
	{
		first=last=newacc;
	}
	else
	{
		newacc->pre=last;
		last->next=newacc;
		last=last->next;
	}
	printf("Succesfully Account Is Created\n");
	n++;
}

int	deposit()/*Deposit Amount*/
{
	int d,fan; /*Fan means Find the account*/
	temp=first;
	
	printf("Account No=");
	scanf("%d",&fan);
	
	if(fan<=n)
	{
		while(temp!=NULL && temp->accno!=fan)
		{
			temp=temp->next;
		}
		
		printf("Account No=%d\n",temp->accno);
		printf("Account Holder Name=%s\n",temp->name);
		printf("Account Current Bal=%d\n",temp->bal);	
		printf("Enter the Deposit Amount=");
		scanf("%d",&d);
		
		if(d<50000)
		{	
			newacc->bal=newacc->bal+d;
			printf("Succesfully %d Deposit in your account\n",d);
		}	
		else
		{
			printf("You cross the deposit limeted\n");
		}
	}
	else
	{
		printf("This account number is Not Created\n");
	}
	getch();
}
int	withdraw()/*Withdraw Amount*/
{
	int w,fan;/*Fan means Find the account*/
	
	temp=first;
	printf("Account No=");
	scanf("%d",&fan);
	
	if(n>=fan)
	{
		while(temp!=NULL && temp->accno!=fan)
		{
			temp=temp->next;
		}
		
		printf("Account No=%d\n",temp->accno);
		printf("Account Holder Name=%s\n",temp->name);
		printf("Account Current Bal=%d\n",temp->bal);	
		printf("Enter the Withdraw Amount=");
		scanf("%d",&w);
		
		if(temp->bal>=w)
		{
			newacc->bal=newacc->bal-w;
			printf("Succesfully %d Withdraw in your account\n",w);
		}
		else
		{
			printf("Low Balance\n");
		}
	}
	else
	{
		printf("This account number is Not Created\n");
	}
	getch();
}
int	checkbal()/*Check Balance in account*/
{
	int fan;/*Fan means Find the account*/
	
	temp=first;
	printf("Account No=");
	scanf("%d",&fan);
	
	if(n>=fan)
	{
		while(temp!=NULL && temp->accno!=fan)
		{
			temp=temp->next;
		}
		
		printf("Account No=%d\n",temp->accno);
		printf("Account Holder Name=%s\n",temp->name);
		printf("Account Current Bal=%d\n",temp->bal);
	}
	else
	{
		printf("This account number is Not Created\n");
	}
	getch();
}
int checkacc()/*Check all acount in the bank*/
{
	temp=first;
	
	while(temp!=NULL)
	{
		printf("Account No=%d\n",temp->accno);
		printf("Account Holder Name=%s\n",temp->name);
		
		temp=temp->next;
	}
	getch();
}
int deacc()/*Delete the account*/
{
	
	int fan,ch;/*Fan means Find the account*/
	
	temp=first;
	printf("Account No=");
	scanf("%d",&fan);
	
	if(n>=fan)
	{
		while(temp!=NULL && temp->accno!=fan)
		{
			temp=temp->next;
		}
		
		printf("Account No=%d\n",temp->accno);
		printf("Account Holder Name=%s\n",temp->name);
		printf("All Amount is Withdraw=%d\n",temp->bal);
		printf("You Confirm to delete account\n");
		printf("1.Yes\n2.No\n=");
		scanf("%d",&ch);
		
		if(ch==1)
		{
			if(temp==first)
			{
				first=temp->next;
				first->pre=0;
				free(temp);
			}
			else if(temp==last)
			{
				last=last->pre;
				last->next=0;
				free(temp);
			}
			else
			{
				temp->next->pre=temp->pre;
				temp->pre->next=temp->next;
				free(temp);
			}
			printf("Succesfully deleted account\n");
		}
	     if(ch==2)
		{
			printf("cencel for delete account\n");
			getch();
		}
		
		
		
	}
	else
	{
		printf("This account number is Not Created\n");
	}
	getch();
}
													
