#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int create();
int dis();
int ins_first();
int ins_last();
int del_first();
int del_last();
int inspos_bf();
int inspos_af();

int inspos1_bf();
int inspos1_af();
int del_any();
int search();
int update();

int n=0;


 struct stud
 {
	int  no;
	struct stud *next,*prev;

 } *temp,*first,*last,*new1;


int main()
{
	int k;

    system("cls");
	printf("1.create\n");
	printf("2.display\n");
	printf("3.exit\n");
	printf("4.insert first\n");
	printf("5.inser last\n");
	printf("6.delete first\n");
	printf("7.delete last\n");
	printf("8.delete any place\n");
	printf("9.insert anyplace befor\n");
	printf("10.insert anyplace after\n");
	printf("11.insert anyplace to pos before\n");
	printf("12.insert anyplace to pos after\n");
	printf("13.search node\n");
	printf("14.update node\n");


	 printf("\n TOTAL NODE=%d\n",n);
	printf("Enter your choice=");
	scanf("%d",&k);

	switch(k)
	{
		case 1:
		create();
		main();

		case 2:
		dis();
		main();

		case 3:
		exit(0);

		case 4:
		ins_first();
		main();

		case 5:
		ins_last();
		main();

		case 6:
		del_first();
		main();

		case 7:
		del_last();
		main();

		case 8:
		del_any();
		main();

		case 9:
		inspos_bf();
		main();

		case 10:
		inspos_af();
		main();

		case 11:
		inspos1_bf();
		main();

		case 12:
		inspos1_af();
		main();

		case 13:
			search();
			main();

		case 14:
			update();
			main();




		default:
		printf("WRONG CHOICE");

	}

	getch();
}

int create()
{
	new1=(struct stud *)malloc(sizeof(struct stud));

	printf("\nEnter the number=");
	scanf("%d",&new1->no);
	new1->next=0;
	new1->prev=0;

	if(first==0)
	{
		first=new1;
		last=new1;

	}
	else
	{
		last->next=new1;
		new1->prev=last;
		last=new1;


	}
	n++;
}
int dis()
{
	int i;

	temp=first;
       //	for(i=1;i<=n;i++)
	 while(temp!=NULL)
	{
		printf("prev=%d  no=%d   next=%d\n",temp->prev,temp->no,temp->next);
		temp=temp->next;
	}

	printf("\n");
	temp=first;
	while(temp!=NULL)
	{
		printf("%d->",temp->no);
		temp=temp->next;

	}
	printf("____________");
	temp=last;
	while(temp!=NULL)
	{
		printf("<-%d",temp->no);
		temp=temp->prev;
	}
	getch();
}
int ins_first()
{
	new1=(struct stud*)malloc(sizeof(struct stud));

	printf("\nEnter the no=");
	scanf("%d",&new1->no);

	 new1->next=0;
	 new1->prev=0;
	if(first==0)
	{
		first=last=new1;

	}
	else
	{
		new1->next=first;
		first->prev=new1;
		first=new1;

	}

	n++;
	getch();


}
int ins_last()
{
	create();
}
int del_first()
{
	temp=first;

	if(first==NULL)
	{
		printf("list is empty");
	}
	else
	{
		if(first==last)
		{
			first=last=NULL;
			free(temp);
		}
		else
		{
			first=first->next;
			first->prev=NULL;
			free(temp);

		}
	}
	getch();
	n--;
}
int del_last()
{

	temp=last;
	 if(last==NULL)
	 {
		printf("LIST IS EMPTY");

	 }
	 else
	 {
		if(first==last)
		{
			first=last=NULL;
			free(temp);
		}
		else
		{
			last=last->prev;
			last->next=0;
			free(temp);
		}
	 }
	 getch();
	 n--;
}
int inspos_bf()
{
	int pos;
	printf("Enter the value=");
	scanf("%d",&pos);

	new1=(struct stud*)malloc(sizeof(struct stud));

	printf("Enter the node value=");
	scanf("%d",&new1->no);
	new1->next=0;
	new1->prev=0;

	temp=first;
	while(temp!=NULL && temp->no!=pos)
	{
		temp=temp->next;
	}
	if(temp==first)
	{

		new1->next=temp;
		temp->prev=new1;
		first=new1;

	}
	else
	{
		temp->prev->next=new1;
		new1->prev=temp->prev;
		new1->next=temp;
		temp->prev=new1;

	}
	getch();
	n++;
	}
int inspos_af()
{
	int pos;
	printf("Enter the value=");
	scanf("%d",&pos);

	new1=(struct stud*)malloc(sizeof(struct stud));
	printf("Enter the node value=");
	scanf("%d",&new1->no);

	new1->prev=0;
	new1->next=0;

	temp=first;
	while(temp!=NULL && temp->no!=pos)
	{
		temp=temp->next;
	}

	if(temp==last)
	{
		new1->prev=temp;
		temp->next=new1;
		last=new1;

	}
	else
	{
		temp->next->prev=new1;
		new1->next=temp->next;
		new1->prev=temp;
		temp->next=new1;
	}
	getch();
	n++;

}
int inspos1_bf()

{
	int pos,i;
	printf("Enter the position=");
	scanf("%d",&pos);

	new1=(struct stud*)malloc(sizeof(struct stud));
	printf("Enter the node value=");
	scanf("%d",&new1->no);

	new1->next=0;
	new1->prev=0;;
	if(first==0)
	{
		first=last=new1;

	}
	else
	{
		for(i=0;i<pos-1;i++)
		{
			temp=temp->next;
		}
			temp->prev->next=new1;
			new1->prev=temp->next;
			new1->next=last;
			temp->prev=new1;


       }
       getch();
       n++;
}
int inspos1_af()
{


}
int del_any()
{
	int pos;
	temp=first;
	printf("Enter the value=");
	scanf("%d",&pos);

	while(temp!=NULL && temp->no!=pos)
	{
		temp=temp->next;

	}
	printf("deleted value=%d\n",temp->no);


	if(temp==NULL)
	{
		printf("a bhai khali se list");
	}
	else if(first==last)
	{
		first=last=0;
		free(temp);
	}
	else if(temp==first)
	{
		first=first->next;
		first->prev=0;
		free(temp);

	}
	else if(temp==last)
	{
		last=last->prev;
		last->next=0;
		free(temp);
	}
	else
	{
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);
	}


	getch();
	n--;
}

int search()
{
	int ser,m=0,k=0;

	temp=first;
	printf("Enter the search value=");
	scanf("%d",&ser);

	while(temp!=NULL && temp->no!=ser)
		{
			temp=temp->next;


		}

	  if(temp==NULL  && ser!=temp->no)
	  {
		printf("LIST IS EMPTY  OR  THIS  IS NOT IN LIST");
		getch();
	  }
	  else
	  {

		printf("search is sucessfully and \n search value=%d",temp->no);
	   }



	getch();
}

int update()
{
	int ser,m=0,k=0,upd;

	temp=first;
	printf("Enter the search value=");
	scanf("%d",&ser);

	printf("Enter the update value=");
	scanf("%d",&upd);

	   while(temp!=NULL && temp->no!=ser)
		{
			temp=temp->next;


		}
	  if(temp==NULL  && ser!=temp->no)
	  {
		printf("LIST IS EMPTY  OR  THIS IS NOT IN LIST");
	  }
	  else
	  {

		temp->no=upd;
		printf("update is sucessfully and \n update value=%d",temp->no);
	   }
	  getch();
}
