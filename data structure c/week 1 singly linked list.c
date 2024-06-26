#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;
void create()
{
    head=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value for node 1:");                                                                   
    scanf("%d",&head->data);
    head->next=NULL;
}
void insertbegin()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
}
void insert(int a)
{
    struct node *tmp=head;
    for(int i=1;i<a;i++)
        tmp=tmp->next;
    struct node *newnode=(struct  node *)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&newnode->data);
    newnode->next=tmp->next;
    tmp->next=newnode;
    }
void insertend()
{
    struct node *tmp=head;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    tmp->next=newnode;

}
void find(int b)
{ 
    int i=1;
    struct node *tmp=head;
    while(tmp!=NULL)
    {
        if(tmp->data==b)
        {
          printf("It is at node %d.\n",i);
          break;
        }
        if(tmp->next==NULL)
          printf("The element is not found.\n");
        
    
        i++;
        tmp=tmp->next;
    }
    
}
void findnext(int c)
{
   struct node *tmp=head,*nextnode;
   while(tmp!=NULL)
   {
      if(tmp->data==c)
      {
        nextnode=tmp->next;
        printf("The next value is:%d\n",nextnode->data);
        break;
      }
      else if (tmp->next==NULL)
        printf("The element is not found.\n");
      tmp=tmp->next;
   }
}
void findprev(int d)
{
    struct node *tmp=head,*prev;
    while(tmp!=NULL)
    {
        if(tmp->data==d&&tmp==head)
        {
           printf("There is no prev element:");
           break;
        }
        else if(tmp->data==d)
        {
            printf("the prev element is:%d\n",prev->data);
            break;
        }
        else if(tmp->next==NULL)
            printf("the element is not found.\n");
        prev=tmp;
        tmp=tmp->next;
    }
}
void deletebegin()
{
    struct node *tmp=head;
    head=head->next;
    free(tmp);
}
void deleteend()
{
    struct node *tmp=head,*prev;
    while(tmp->next!=NULL)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    prev->next=NULL;
    free(tmp);
}
void delete(int p)
{
    struct node *tmp=head,*prev;
    for(int i=1;i<p;i++)
    {
        prev=tmp;
        tmp=tmp->next;
    }
    prev->next=tmp->next;
    free(tmp);
}
void traverse()
{
    struct node *temp=head;
    int j=1;
    while(temp!=NULL)
    {
        printf("the value of node %d:%d\n",j,temp->data);
        temp=temp->next;
        j++;
    }
}
void main()
{
    int a,b,n,m,k,d,e;
    create();
    printf("0=end.\n1=inserting a node.\n2=finding a element.\n3=printing the element.\n4=deleting the element.\n");
    scanf("%d",&a);
    while(a)
    {                                                                                                                                                    
        if (a==1)
        {
            printf("1=insert node at end.\n2=insert node at beginning.\n3=insert node after p.\n");
            scanf("%d",&b);
            if(b==1)
                insertend();
            if(b==2)
                insertbegin();
            if(b==3)
            {   
                printf("after which node do you want to insert:");
                scanf("%d",&n);
                insert(n);
            }
        }
        if(a==2)
        {
            printf("1=finding the element.\n2=finding the next element.\n3=finding the previous element.\n");
            scanf("%d",&m);
            printf("Enter the element:");
            scanf("%d",&k);
            if(m==1)
               find(k);
            if(m==2)
               findnext(k);
            if(m==3)
               findprev(k);
        }
        if(a==3)
           traverse();
        if(a==4)
          {
            printf("1=delete at end.\n2=delete at beginning.\n3=delete at p.\n");
            scanf("%d",&d);
            if(d==1)
              deleteend();
            if(d==2)
              deletebegin();
            if(d==3)
            {
                printf("Enter the node to be deleted:");
                scanf("%d",&e);
                delete(e);
            }
          }
        printf("0=end.\n1=inserting a node.\n2=finding a element.\n3=printing the element.\n4=deleting the element.\n");
        scanf("\n%d",&a);
    }
}