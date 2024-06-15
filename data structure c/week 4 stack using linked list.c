#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next; 
    struct node *prev;
}*head=NULL;
typedef struct node node;
node *top=NULL;
void push()
{
   node *newnode=(node *)malloc(sizeof(node));
   printf("Enter the value to push:");
   scanf("%d",&newnode->data);
   newnode->next=NULL;
   if(top==NULL)
   {
      head=newnode;
      newnode->prev=NULL;
   }
   else
   {
      top->next=newnode;
      newnode->prev=top;
   }
   top=newnode;
   
}
void pop()
{
    if(top==NULL)
      printf("The stack is underflow!!!");
    else
    {
      printf("The value to pop:%d",top->data);
      top=top->prev;
      free(top->next);
      top->next=NULL;
    }
      
}
void display()
{
    if(top==NULL)
      printf("There is no value in stack!!");
    else
    {
        node *tmp=head;
        printf("The values in the stack are:\n");
        while(tmp!=NULL)
        {
            printf("%d ",tmp->data);
            tmp=tmp->next;
        }
    }
    
}
void main()
{
    int a;
    do
    {
       printf("\nEnter an choice.\n1.push\n2.pop\n3.display\n4.top\n5.exit\n");
       scanf("%d",&a);
       switch(a)
       {
        case 1:
          push();
          break;
        case 2:
          pop();
          break;
        case 3:
          display();
          break;
        case 4:
          printf("top element:%d",top->data);
          break;
        case 5:
          break;
                 default:
          printf("Enter a valid choice!!!");

       }
    }while(a!=4);
}