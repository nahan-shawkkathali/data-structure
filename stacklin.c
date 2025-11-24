#include <stdio.h>
#include <stdlib.h>   
#define max_size 3
int counter = 0;
struct stack
{
    int data;
    struct stack *link;   
};
struct stack *top = NULL;
void push(int item)
{
    struct stack *newnode;
    newnode = (struct stack *)malloc(sizeof(struct stack));
    newnode->data = item;
    newnode->link = NULL;

    if (top == NULL)
    {	
        top = newnode;
        counter = counter + 1;
    }
    else
    {	
        if (counter < max_size)
        {
            newnode->link = top;
            top = newnode;
            counter = counter + 1;
        }
        else
        {
            printf("stack is full\n");   
        }
    }
}
void pop()
{
    struct stack *ptr;
    if (top != NULL)
    {
        ptr = top;
        top = top->link;
        free(ptr);
        counter--;                 
    }
    else
    {
        printf("Empty stack, Deletion is not possible....\n");
    }
}
void traversestack()
{	
    struct stack *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}
int main()
{
    int choice, item;
    do 
    {	
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {	
            case 1:
                printf("Enter the element to insert at Front: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("The elements in list:\n");
                traversestack();
                break;
            case 4:
                break;
            default: 
                printf("Enter the correct choice...\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

