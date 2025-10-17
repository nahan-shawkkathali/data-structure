#include<stdio.h>
#define max_size 3

int queue[max_size];
int front = -1, rear = -1;

void display()
{
    int i;
    if(front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int item)
{
    if(rear == max_size - 1)
    {
        printf("Queue is full..\n");
        return;
    }
    if(front == -1) 
        front = 0;
    
    rear++;
    queue[rear] = item;
    printf("%d is enqueued successfully\n", item);
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty...\n");
        return;
    }
    int item = queue[front];
    front++;
    printf("The dequeued element is: %d\n", item);

    
    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

int main()
{
    int choice, item;
    do
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Enter the correct choice.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}

