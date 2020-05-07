//Implementing a Stack using Linked List
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
};

int val;
struct node *head = NULL;
struct node *push(struct node*, int);
void display(struct node*);
void peek(struct node*);
struct node* pop(struct node*);

int main()
{
  int option;

  do{
  printf("******MENU****\n");
  printf("\nEnter 1 to PUSH \nEnter 2 to Display whole Stack \nEnter 3 to PEEK Top Element \nEnter 4 to POP Top element from stack \nEnter 5 to EXIT \nOPTIONS ENTER\n");
  scanf("%d", &option);


    switch(option)
    {
    case 1:
          printf("\nEnter value to push onto stack\n");
          scanf("%d", &val);
          head = push(head, val);
          break;

    case 2:
          display(head);
          break;

    case 3:
          peek(head);
          break;

    case 4:
          head = pop(head);
          break;

    case 5:
          break;

    default:
            printf("Wrong statement , Thus Exitng Loop\n");
            break;
    }

  }while(option!=5);

  return 0;
}

struct node* push(struct node* head, int val)
{
  struct node* ptr;

  if(head == NULL)
  {
    head = (struct node*)malloc(sizeof(struct node));
    head->data = val;
    head->next = NULL;
  }
  else
  {
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = head;
    head = ptr;
  }

  return head;
}

void display(struct node* first)
{
  struct node *ptr;
  ptr = first;
  while(ptr!= NULL)
  {
    printf("%d \n",ptr->data);
    ptr = ptr->next;
  }
}

void peek(struct node* first)
{
  if(first == NULL)
  printf("Stack is Empty\n");
  else
  {
   struct node* ptr;
   ptr = first;
   printf("The top element is %d", ptr->data);
 }
}

struct node *pop(struct node* first)
{
  struct node* ptr;
  ptr = first;
  if(first == NULL)
  printf("Stack is Empty\n");
  else
  {
    first = first->next;
    val = ptr->data;
    free(ptr);
    printf("\nThe element deleted from the stack is %d", val);
  }
  return first;
}
