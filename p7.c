//Stacks using Arrays
#include<stdio.h>


int stack[100];
int max=100, top=-1;
int peek(int stack[]);
void display(int *);
void push(int *, int val);
int pop(int *);

int main()
{
  int val, option;
  do{

  printf("\nMain Menu\n");
  printf("\n1 PUSH \n2 POP \n3 PEEK \n4 DISPLAY \n5 EXIT");
  printf("\nEnter Option\n");
  scanf("%d", &option);


  switch(option)
  {
    case 1:
          printf("Enter the number to push on stack\n");
          int n;
          scanf("%d", &n);
          push(stack, n);
          break;

    case 2:
          val;
          val = pop(stack);
          if(val!=-1)
          printf("The value deleted from the stack is %d",val);
          break;

    case 3:
          val = peek(stack);
          if(val!=-1)
          printf("The value stored at the top of the stack is %d",val);
          break;

    case 4:
            display(stack);
            break;

  }
}while(option!=5);


return 0;
}

void push(int st[], int val)
{
  if(top == max-1)
  printf("Stack Overflow");
  else
  {
    top++;
    st[top] = val;
  }
}

int pop(int stack[])
{
  int val;
  if(top == -1)
  {
   printf("\nStack Overflow\n");
   return -1;
 }
 else
 {
   val = stack[top];
   top--;
   return val;
 }
}

void display(int stack[])
{
  if(top==-1)
  printf("\nStack is Empty\n");
  else
  {
    for(int i=top; i>=0; i--)
    printf("\n %d",stack[i]);
    printf("\n");
  }
}

int peek(int stack[])
{
  if(top == -1)
  {
   printf("\nStack is Empty\n");
   return -1;
 }
 else
  return(stack[top]);
}
