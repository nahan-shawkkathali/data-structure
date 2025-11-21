#include<stdio.h>
#include<stdlib.h>
#define max_size 3
int counter=0;
struct stack
{
	int data;
	struct stack *link;
};
struct stack *TOP=NULL;
void push(int item)
{
	struct stack *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=NULL;
	if(TOP==NULL)
	{
		TOP=newnode;
	}
	else
	{
		if(counter < MAX_SIZE)
		{
		
			newnode->link=top;
			TOP=newnode;
			counter=counter+1;
		}
		else
		print("Stack is full");
	}
	
}
/*void pop()
{
	struct node *ptr;
	if(TOP==NULL)
	{
		printf("Empty list.Deletion not possible");
	}
	else
	{
		ptr=TOP;
		TOP=TOP->link;
		printf("Deleted element is %d\n",ptr->data);
		free(ptr);
		
	}
}
void traversestack()
{
	struct node *ptr;
	ptr=TOP;
	while(ptr!=NULL)
	{
		printf("%d\n",ptr->data);
		ptr=ptr->link;
	}
}*/
int main()
{
	 int choice;
    do
    {
    	printf("\n\n----------Stack Menu-----------\n\n\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to push in stack: ");
                scanf("%d", &item);
		push(item);
		printf("The element %d is pushed successfully...\n",item);
                break;
           /* case 2:
            	pop();
            	break;
            case 3:
          	  printf("The elements in the list:\n");
            	  traversestack();
            	  break;*/
            case 2:
            	break;
            default:
                printf("Enter the correct choice.\n");
                break;
        }
    } while(choice != 2);
	return (0);                                
}

	

