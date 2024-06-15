#include<stdio.h>
#include<stdlib.h>                                                             
int top=-1,n,*stack;
void push()
{
     if(top>=n-1)
       printf("the stack is in overflow!!!");
    else
    {
        printf("enter the value to push:");
        scanf("%d",&stack[++top]);
    }
}
void pop()
{
    if(top<=-1)
      printf("the stack is in underflow!!!");
    else
    {
        printf("the value to be pop:%d",stack[top]);
        top--;
    }
}
void display()
{
    if(top<=-1)
      printf("there is no value in the stack!!!");
    else
    {
        printf("the values are:");
        for(int i=0;i<=top;i++)
            printf("%d ",stack[i]);
        
    }
}
void main()
{
    int a;
    printf("Enter the MAX size for stack:");
    scanf("%d",&n);
    stack=(int*)malloc(n*sizeof(int));
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
          printf("top element:%d",stack[top]);
          break;         
        case 5:
          break;
        default:
          printf("Enter a valid choice!!!");

       }
    }while(a!=4);
    free(stack);
}