//Program to reverse a linked list
#include<stdio.h>
#include<stdlib.h>


struct node
{
  int data;
  struct node * next;
};


void reverseprint(struct node *);
void reverse(struct node*);
void display();
struct node *head = NULL;

int main()
{
  printf("Creation of the  linked list \n");

  struct node* new_node;
  struct node* ptr;
  int val;
  printf("\nEnter -1 to exit input loop\n");
  do
  {
  printf("Enter the value for the linked list\n");
  scanf("%d", &val);
  new_node = (struct node*)malloc(sizeof(struct node));
  new_node -> data = val;
  if(head == NULL)
  {
    new_node -> next = NULL;
    head = new_node;
  }
  else
  {
    ptr = head;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->next = new_node;
    new_node->next = NULL;
  }


}while(val!=-1);

printf("\nThe linked list created is \n");
ptr = head;
while(ptr!= NULL)
{
  printf("\t %d", ptr->data);
  ptr = ptr->next;
}
printf("\n Reversing the Linked list using iterative method \n");

struct node *current, *next, *prev;
prev = NULL;
current = head;
while(current!= NULL)
{
  next = current->next;
  current ->next = prev;
  prev = current;
  current = next;
}
head = prev;

printf("\nThe reverse linked list is \n");
ptr = head;
while(ptr!= NULL)
{
  printf("\t %d", ptr->data);
  ptr = ptr->next;
}

printf("\nReversing the linked list using recursion traversal \n");
reverseprint(head);
printf("\nActual reversal of a linked list using recursion \n");
reverse(head);
printf("%d", head->data);
return 0;
}

void reverseprint(struct node *p)
{
  if(p==NULL)
    return;
  reverseprint(p->next);
  printf("%d ",p->data);
}


void reverse(struct node *p)
{

  if(p->next=NULL)
  {
    head = p;
    return;
  }
  reverse(p->next);
  struct node *q;
  q = p->next;
  q->next = p;
  p->next = NULL;

}
