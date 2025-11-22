#include<stdio.h>
#define MAX_SIZE 5

int cq[MAX_SIZE];
int front = -1, rear = -1;

void enque(int item){
    int next;

    if(front == -1 && rear == -1)   // FIXED condition
    {
        front = rear = 0;
        cq[rear] = item;
    }
    else{
        next = (rear + 1) % MAX_SIZE;

        if(next != front)   // space available
        {
            rear = next;    // FIXED missing rear update
            cq[rear] = item;
        }
        else
        {
            printf("Queue is full\n");
            return;
        }
    }
    printf("item %d inserted\n", item);
}

void deque()  // item argument removed (wrong)
{
    if(front == -1)     // FIXED
    {
        printf("Queue empty\n");
        return;
    }

    int item = cq[front];

    if(front == rear)    // only one element
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }

    printf("deleted item %d\n", item);
}

void display(){
    if(front == -1)
    {
        printf("Queue empty\n");
        return;
    }
    
    printf("Queue elements: ");

    int i = front;
    while(1)
    {
        printf("%d ", cq[i]);
        if(i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main(){
    int choice, item;

    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enque(item);
                break;

            case 2:
                deque();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    }while(choice != 4);

    return 0;
}
