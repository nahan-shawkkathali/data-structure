#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *header=NULL;
void insertAtFront(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=NULL;
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		newnode->link=header;
		header=newnode;
	}
}
void insertAtEnd(int item)
{
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=item;
	newnode->link=NULL;
	if(header==NULL)
	{
		header=newnode;
	}
	else
	{
		struct node *ptr;
		ptr=header;
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}
void insertAtAny(int key,int item)
{
	struct node *ptr,*ptr1;
	ptr=ptr1=header;
	while(ptr!=NULL && ptr->data!=key)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		if(ptr==NULL)
		{
			printf("key not found, insertion not possible");

		}
		else
		{
			struct node *newnode;
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->data=item;
			newnode->link=ptr;
			ptr1->link=newnode;
			printf("The element %d is inserted successfully...\n",item);
		}
}
void deleteAtFirst()
{
	struct node *ptr;
	if(header==NULL)
	{
		printf("Empty list.Deletion not possible");
	}
	else
	{
		ptr=header;
		header=header->link;
		printf("Deleted element is %d\n",ptr->data);
		free(ptr);
		
	}
}
void deleteAtEnd()
{
	struct node *ptr,*ptr1;
	ptr=header;
	if(header==NULL)
	{
		printf("Empty list.Deletion is not possible");
	}
	else
	{
		while(ptr->link!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->link;
		}
		printf("Deleted element is %d\n",ptr->data);
		ptr1->link=NULL;
		free(ptr);
	}
}
void deleteAtAny(int key)
{
	struct node *ptr,*ptr1;
	ptr=ptr1=header;
	while(ptr!=NULL && ptr->data!=key)
		{
			ptr1=ptr;
			ptr=ptr->link;
			
		}
		if(ptr==NULL)
		{
			printf("key not found, insertion not possible");
		}
		else
		{
		printf("Deleted element is %d\n",ptr->data);
		if(ptr1 !=NULL)
		{
			ptr1->link=ptr->link;
		}
		else
		{
			header=ptr->link;
		}
		free(ptr);
	}
}
	
void traverselist()
{
	struct node *ptr;
	ptr=header;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
}
int main()
{
	 int choice, key,item;
    do
    {
    	printf("\n\n----------Single Linkedlist Menu-----------\n\n\n");
        printf("1. Insert at front\n2. Insert at end\n3. Insert at any\n4. Delete at front\n5. Delete at end\n6. Delete at Any\n7. Display\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
		insertAtFront(item);
		printf("The element %d is inserted successfully...\n",item);
                break;
            case 2:
                printf("Enter the element to insert at end: ");
                scanf("%d", &item);
		insertAtEnd(item);
		printf("The element %d is inserted successfully...\n",item);
                break;
            case 3:
                printf("enter the key ");
                scanf("%d", &key);
                printf("Enter the element to insert at any");
                scanf("%d", &item);
		insertAtAny(key,item);
                break;
            case 4:
            	deleteAtFirst();
            	break;
            case 5:
            	deleteAtEnd();
            	break;
            case 6:
            	printf("enter the key ");
                scanf("%d", &key);
            	deleteAtAny(key);
            case 7:
            	printf("The elements in the list:\n");
            	traverselist();
            	break;
            case 8:
            	break;
            default:
                printf("Enter the correct choice.\n");
                break;
        }
    } while(choice != 8);
	return (0);                                
}

	

