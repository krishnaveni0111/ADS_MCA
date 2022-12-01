#include<stdio.h>
#include<stdlib.h>
struct node
{
  struct node *prev;
  struct node *next;
  int data;
};
struct node *head;
void insert_begin();
void insert_last();
void insert_specified();
void delete_begin();
void delete_last();
void delete_specified();
void display();
void search();
void main()
{
   int choice=0;
   clrscr();
   while(choice!=9)
   {
      printf("\n ********* MAIN MENU*********\n");
      printf("\n choose one option from the following list...\n");
      printf("\n 1.insert in beginning \n 2.insert at last \n 3.insert at any random location\n 4.delete from beginning\n 5.delete from last\n 6.delete the node after data\n 7.search\n 8.show\n 9.exit \n");
      printf("\n enter your choice\n");
      scanf("\n %d",&choice);
      switch(choice)
      {
      case 1:
      insert_begin();
      break;
      case 2:
      insert_last();
      break;
      case 3:
      insert_specified();
      break;
      case 4:
      delete_begin();
      break;
      case 5:
      delete_last();
      break;
      case 6:
      delete_specified();
      break;
      case 7:
      search();
      break;
      case 8:
      display();
      break;
      case 9:
      exit(0);
      break;
      default:
      printf("please enter valid choice...");
      }
    }
  }
  void insert_begin()
  {
  struct node *ptr;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
  {
      printf("\n overflow");
  }
  else{
  printf("\n enter item value");
  scanf("%d",&item);
  if(head==NULL)
  {
     ptr->next=NULL;
     ptr->prev=NULL;
     ptr->data=item;
     head=ptr;
  }else{
  ptr->data=item;
  ptr->prev=NULL;
  ptr->next=head;
  head->prev=ptr;
  head=ptr;
  }
  printf("\n node inserted\n");
 }
}
void insert_last()
{
   struct node *ptr,*temp;
   int item;
   ptr=(struct node *)malloc(sizeof(struct node));
   if(ptr==NULL)
   {
     printf
     ("\n overflow");
   }
   else{
   printf("enter value\n");
   scanf("%d",&item);
   ptr->data=item;
   if(head==NULL)
   {
      ptr->next=NULL;
      ptr->prev=NULL;
      head=ptr;
      }
      else{
      temp=head;
      while(temp->next!=NULL)
      {
	temp=temp->next;
       }
       temp->next=ptr;
       ptr->prev=temp;
       ptr->next=NULL;
       }
      }
     printf("\n node inserted\n");
   }
   void insert_specified()
   {
     struct node *ptr,*temp;
     int item,loc,i;
     ptr=(struct node *)malloc(sizeof(struct node));
     if(ptr==NULL)
     {
      printf("\n overflow");
     }
     else{
     temp=head;
     printf("enter the location");
     scanf("%d",&loc);
     for(i=0;i<loc;i++)
     {
	 temp=temp->next;
	 if(temp==NULL)
	 {
	 printf("\n there are less than %d elements",loc);
	 return;
	 }
    }
    printf("enter value");
    scanf("%d",&item);
    ptr->data=item;
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;
    temp->next->prev=ptr;
    printf("\n node inserted\n");
    }
  }
  void delete_begin()
  {
  struct node  *ptr;
  if(head==NULL)
  {
  printf("\n underflow");
  }
else if(head->next==NULL){
head=NULL;
free(head);
printf("\n node deleted \n");
}else{
ptr=head;
head=head->next;
head->prev=NULL;
free(ptr);
printf("\n node deleted\n");
}
}
void delete_last()
{
 struct node *ptr;
 if(head==NULL)
 {
 printf("\n underflow");
 }else if(head->next==NULL)
 {
 head=NULL;
 free(head);
 printf("\n node deleted \n");
 }else{
 ptr=head;
 if(ptr->next!=NULL)
 {
   ptr=ptr->next;
 }
    ptr->prev->next=NULL;
    free(ptr);
    printf("\n node deleted \n");
    }
 }
 void delete_specified()
 {
   struct node *ptr,*temp;
   int val;
   printf("\n enter the data after which the node to be deleted:");
   scanf("%d",&val);
   ptr=head;
   while(ptr->data!=val)
   ptr=ptr->next;
   if(ptr->next==NULL)
   {
     printf("\n can't delete\n:");
     }
     else if(ptr->next->next==NULL)
     {
     ptr->next=NULL;
     }else{
     temp=ptr->next;
     ptr->next=temp->next;
     temp->next->prev=ptr;
     free(temp);
     printf("\n node deleted \n");
   }
 }
 void display()
 {
    struct node *ptr;
    printf("\n printing values....\n");
    ptr=head;
    while(ptr!=	NULL)
    {
       printf("%d  <=> ",ptr->data);
       ptr=ptr->next;
    }
    printf("NULL");
   }
    void search()
    {
       struct node *ptr;
       int item,i=0,flag;
       ptr=head;
       if(ptr==NULL)
       {
       printf("\n empty list \n");
       }
       else
       {
       printf("\n enter item which you want to search\n");
       scanf("%d",&item);
       while(ptr!=NULL)
	 {
	   if(ptr->data==item)
	   {
	    printf("\n item found at location %d",i+1);
	    flag=0;
	    break;
	    }else{
	    flag=1;
	    }i++;
	    ptr=ptr->next;
	    }
	    if(flag==1)
	    {
	    printf("\n item not found \n ");
	    }
	 }
      }








