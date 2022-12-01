#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*next;
};
struct node *temp,*newnode,*top=NULL;
void push();
void pop();
void display();
void search();
void main()
{
     int choice=0;
     clrscr();
     do
     {
	 printf("\n *******MAIN MENU********\n");
	 printf("\n 1.push\n 2.pop\n  3.search\n 4.display\n 5.exit\n");
	 printf("enter the choice\n");
	 scanf("%d",&choice);
	 switch(choice)
	 {
	     case 1:
		push();

		break;
	     case 2:
		pop();

		break;

	     case 3:
		search();
		break;
	     case 4:
		 display();
		 break;
	     case 5:
		 exit(0);
		 break;
     }
     }while(choice!=5);
    }
    void push()
    {
    int a,n=1;
    while(n)
    {
    printf("enter the data to be pushed:\t");
    scanf("%d",&a);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=top;
    top=newnode;
    printf("do you want to continue:(1/0)\n");
    scanf("%d",&n);
    }
    }
    void pop()
    {
	temp=top;
	if(top==NULL)
	{
	printf("the list is empty||\n");
	}
	else
	{
	printf("\nthe poped element is %d \n",top->data);
	top=top->next;
	free(temp);
	}
    }

   void search()
   {
    int item,i=1,flag=0;
    printf("enter the element to search:");
    scanf("%d",&item);
    temp=top;
    while(temp!=NULL)
    {
      if(temp->data==item)
      {
	printf("\n\n item found at %d position\n \n",i);
	flag=flag+1;
      }
      i=i+1;
      temp=temp->next;
    }
    if(flag==0)
    {
    printf("\n not found||\n\n");
    }
  }
  void display()
  {
    printf("\n the stack is :\t");
    temp=top;
    if(top=NULL)
    {
       printf("the list is empty||");
    }
    else
    {
      while(temp!=NULL)
      {
      printf("%d\t",temp->data);
      temp=temp->next;
      }
    }
  }




