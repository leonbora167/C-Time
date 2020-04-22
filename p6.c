//Basic Linked List Operations

#include<stdio.h>

//Creating Linked List Structure
struct node
{
	int data;
	struct node* next;
};

struct node* start = NULL;
struct node* create_linked_list(struct node*);
void display(struct node*);
struct node *insert_beginning(struct node *);
struct node *insert_end(struct node*);
struct node *insert_before(struct node*);
struct node *insert_after(struct node*);
struct node *delete_beginning(struct node*);
struct node *delete_end(struct node *);
struct node *sort(struct node *);
struct node *delete_node(struct node*);

int main()
{
	int option;
	do
	{
	
		printf("\nEnter 1 to create a Linked List;");
		printf("\nEnter 2 to Display the List");
		printf("\nEnter 3 to insert element at beginning");
		printf("\nEnter 4 to insert element at end");
		printf("\nEnter 5 to insert an element before a particular element");
		printf("\nEnter 6 to insert an element after a particular element");
		printf("\nEnter 7 to delete beginning of the list");
		printf("\nEnter 8 to delete end of the list");
		printf("\nEnter 9 to sort the list");
		printf("\nEnter 10 to delete any node");
		printf("\nEnter 20 to Exit");
		scanf("%d",&option);
	
		switch(option)
		{
			case 1:
					start = create_linked_list(start);
					break;
					
			case 2:
					display(start);
					break;
					
			case 3:
					start = insert_beginning(start);
					break;
					
			case 4:
					start = insert_end(start);
					break;
					
			case 5:
					start = insert_before(start);
					break;
					
			case 6:
					start = insert_after(start);
					break;
					
			case 7:
					start = delete_beginning(start);
					break;
					
			case 8:
					start = delete_end(start);
					break;
					
			case 9:
					start = sort(start);
					break;
					
			case 10: 
					start = delete_node(start);
					break;
					
			case 20:
					break;
			
			default:
					printf("\nWrong Choice\n");
				
		}
		
	
	}while(option != 20);
	return 0;	
	
	
	
}

//Function to Create Linked List
struct node* create_linked_list(struct node* start)
{
	struct node *ptr, *new_node;
	int num;
	
	printf("\nEnter the values of the Linked List one by one");
	printf("\nEnter -1 to stop the creation");
	printf("\nEnter The Data");
	scanf("\n %d",&num);
	while(num != -1)
	{   
		
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data =num;
		
		if(start == NULL)
		{   
			new_node -> next = NULL;
			start = new_node;
			
		}
		
		else
		{
			ptr = start;
			while(ptr->next!=NULL)
				ptr = ptr->next;
			ptr->next = new_node;
			new_node -> next = NULL;
		}
		printf("\nEnter The Data");
		scanf("\n %d",&num);
	}
	
	return start;
}


//Function to display the Linked List
void display(struct node* start)
{
		struct node *ptr;
		ptr = start;
		while(ptr!=NULL)
		{	
			printf("%d\t",ptr->data);
			ptr = ptr->next;
		}
		
		
}

//Function to insert at beginning
struct node* insert_beginning(struct node* start)
{
	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter the value");
	int n;
	scanf("%d", &n);
	new_node ->data = n;
	new_node -> next = start;
	start = new_node;
	return start;
}

//Function to insert element at end
struct node *insert_end(struct node* start)
{
	struct node *new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	int n;
	printf("\nEnter the data to enter");
	scanf("%d", &n);
	new_node -> data =n;
	struct node *ptr;
	ptr = start;
	while(ptr->next!= NULL)
		ptr = ptr->next;
		
	ptr ->next = new_node;
	new_node -> next = NULL;
	return start;
}

//Function to insert an element before an element
struct node *insert_before(struct node *start)
{
	struct node* new_node, *ptr1, *ptr2;
	printf("\nEnter element to insert");
	int num;
	scanf("%d", &num);
	printf("\nEnter element to insert before that particular element\n");
	int val;
	scanf("%d", &val);
	
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = num;
	
	ptr1 = start;
	while(ptr1 -> data != val)
	{
	
		ptr2 = ptr1;
		ptr1 = ptr1-> next;
	}
	
	ptr2 -> next = new_node;
	new_node -> next = ptr1;
	return start;
}

//Function to insert an element afer an element
struct node* insert_after(struct node* start)
{
	struct node *new_node, *ptr1, *ptr2;
	printf("\nEnter new element\n");
	int num;
	scanf("%d", &num);
	printf("\nEnter value to insert after it");
	int val;
	scanf("%d", &val);
	
	ptr1 = start;
	while(ptr1->data != val)
		ptr1 = ptr1->next;
		
	ptr2 = ptr1->next;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node -> data = num;
	ptr1 -> next = new_node;
	new_node -> next = ptr2;
	return start;
	
}

//Function to delete beginning of the list
struct node *delete_beginning(struct node *start)
{
	struct node *ptr1;
	ptr1 = start;
	start = start->next;
	free(ptr1);
	return start;
}

//Function to delete end of the list
struct node *delete_end(struct node *start)
{
	struct node *ptr1, *ptr2;
	ptr1 = start;
	while(ptr1->next!= NULL)
	{
		ptr2 = ptr1;
		ptr1 = ptr1->next;
	}
	
	ptr2->next = NULL;
	free(ptr1);
	return start;
	
}

//Function to sort the list
struct node *sort(struct node * start)
{
	struct node *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while(ptr1->next != NULL)
	{
		ptr2 = ptr1->next;
		while(ptr2!= NULL)
		{
			if(ptr1->data > ptr2->data)
			{
				temp = ptr1->data;
				ptr1 -> data = ptr2->data;
				ptr2->data = temp;
			}
			ptr2 = ptr2->next;
			
			
		}
		
		ptr1 = ptr1->next;
	}
	
	return start;
}

//Function to Delete any node in the list
struct node* delete_node(struct node *start)
{
	struct node *ptr1, *ptr2, *head;
	head = start;
	printf("\nEnter value to delete");
	int num;
	scanf("%d", &num);
	ptr2 = start;
	ptr1 = start;
	while(ptr1->data != num)
	{
		ptr2 = ptr1;
		ptr1= ptr1->next;
	}
	
	if(head->data == ptr1->data)
	{
		start = head->next;
		free(head);
	}
	else
	{
		ptr2->next = ptr1->next;
		free(ptr1);
	}
	return start;
}

