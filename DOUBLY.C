#include<stdio.h>
#include<conio.h>

void create();
void dis();
void ins_first();
void ins_last();
void inspos_be();
void inspos_af();

int n=0;

struct stud
{
	int no;
	struct stud *next,*prev;

}*temp,*first,*last,*new1;

void main()
{
	int ch;
	clrscr();

	printf("1.create\n");
	printf("2.dis\n");
	printf("3.exit\n");
	printf("4.ins_first\n");
	printf("5.ins_last\n");
	printf("6.inspos_be\n");
	printf("7.inspos_af\n");




	printf("\n TOTAL NODE=%d",n);
	printf("\n Enter your choice=");
	scanf("%d",&ch);



	switch(ch)
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
			inspos_be();
			main();
		case 7:
			inspos_af();
			main();

		default:
			printf("\nWRONG CHOICE");



	}

}
void create()
{
	new1=(struct stud*)malloc(sizeof(struct stud));

	printf("Enter the value=");
	scanf("%d",&new1->no);

	new1->next=0;
	new1->prev=0;

	if(first==0)
	{
		first=last=new1;
	}
	else
	{
		last->next=new1;
		new1->prev=last;
		last=new1;



	}

	n++;
	getch();
}
void dis()
{
	temp=first;
	while(temp!=NULL)
	{
		printf("prev=%d      no=%d      next=%d\n",temp->prev,temp->no,temp->next);
		temp=temp->next;

	}
	temp=first;
	while(temp!=NULL)
	{
		printf("%d->",temp->no);
		temp=temp->next;
	}

	getch();
}
void ins_first()
{
	new1=(struct stud*)malloc(sizeof(struct stud));

	printf("Enter the value=");
	scanf("%d",&new1->no);

	if(first==0)
	{
		first=last=new1;
	}
	else
	{
		new1->next=first;
		first->prev=new1;
		new1->prev=0;
		first=new1;
	}
	n++;
	getch();
}
void ins_last()
{
	create();
}

void inspos_be()
{
	int pos;
	printf("Enter the position value=");
	scanf("%d",&pos);

	new1=(struct stud*)malloc(sizeof(struct stud));

	printf("Enter the value=");
	scanf("%d",&temp->no);

	new1->next=0;
	new1->prev=0;

	temp=first;
	while(temp!=NULL && temp->no!=pos)
	{
		temp=temp->next;
	}
	if(temp==first)
	{
		new1->next=first;
		first->prev=new1;
		first=new1;

	}

	else
	{
		temp->prev->next=new1;

		new1->prev=temp->prev;
		new1->next=temp;
		temp->prev=new1;


	}
	n++;
	getch();
}

void inspos_af()
{

}