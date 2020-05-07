//Linear Queue using Arrays
#include<stdio.h>
#include<stdlib.h>

int val, rear=-1, front=0, max=100;
int queue[100];
int option;
void push(int *, int);
void display(int *);
void peek(int *);
void pop(int *);

int main()
{
  do {

    printf("\nMenu\n");
    printf("Enter 1 to PUSH an element into Queue \nEnter 2 To display the whole Queue \nEnter 3 to PEEK the Top Element \nEnter 4 to POP the Top Element \nEnter 5 to EXIT\n");
    scanf("%d", &option);
    switch(option)
    {
      case 1:
              printf("\nEnter Value to insert into queue\n");
              scanf("%d", &val);
              push(queue, val);
              break;

      case 2:
              display(queue);
              break;

      case 3:
              peek(queue);
              break;

     case 4:
            pop(queue);
            break;
    case 5:
          break;
    }
  }while(option!=5);

}

void push(int queue[], int val)
{
  if(rear > max-1)
    printf("\nQUEUE OVERFLOW\n");
  else
  {
    rear++;
    queue[rear] = val;
  }
}

void display(int queue[])
{
  for(int i=front; i<=rear; i++)
    printf("\n %d", queue[i]);
  printf("\n");
}

void peek(int queue[])
{
  printf("\nThe element at the top of the queue is %d \n", queue[front]);
}

void pop(int queue[])
{
  int a = queue[front];
  front++;
  printf("The value removed from the queue is %d\n", queue[front]);
}
