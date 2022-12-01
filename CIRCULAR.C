#include<stdio.h>
#include<conio.h>
#define size 5
void insertq(int[],int);
void deleteq(int[]);
void display(int[]);
int front=-1;
int rear=-1;
int main()
{
      int n,ch;
      int queue[size];
  do
   {
       printf("\n circular queue:\n 1.insert\n 2.delete \n 3.display \n4.exit");
       printf("\n enter choice:");
       scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n enter number:");
scanf("%d",&n);
insertq(queue,n);
break;
case 2:
deleteq(queue);
break;
case 3:
display(queue);
break;
}
}while(ch!=0);
}
void insertq(int queue[],int item)
{
if((front==0 && rear==size-1)||(front==rear+1))
{
printf("queue is full\n");
return;
}
elseif(rear==-1)
{
rear ++;
front ++;
}
elseif(rear==size-1&&front>0)
{
rear=0;
}
else
{
rear++;
}
queue[rear]=item;
}
void display(int queue[])
{
int i;
printf("\n");
if(front>rear)
{
for(i=front;i<size;i++)
{
printf("%d",queue[i]);
}
for(i=0;i<=rear;i++)
{
printf("%d",queue[i]);
}
}
void deleteq(int queue[])
{
if (front==-1)
{
printf("queue is empty");
}
elseif(front==rear)
[
printf("\n %d deleted",queue[front]);
front=-1;
rear=-1;
}
else
{
printf("\n %d deleted",queue[front]);
front++;
}
}

