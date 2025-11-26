#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *header = NULL;

// Insert at Front
void insertAtFront(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = header;
    header = newnode;

    printf("The element %d is inserted successfully...\n", item);
}

// Insert at End
void insertAtEnd(int item) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = NULL;

    if (header == NULL) {
        header = newnode;
    } else {
        struct node *ptr = header;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = newnode;
    }

    printf("The element %d is inserted successfully...\n", item);
}

// Insert before a key
void insertAtAny(int key, int item) {
    struct node *ptr = header, *ptr1 = NULL;

    while (ptr != NULL && ptr->data != key) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key not found, insertion not possible.\n");
        return;
    }

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->link = ptr;

    if (ptr == header) {
        header = newnode;
    } else {
        ptr1->link = newnode;
    }

    printf("The element %d is inserted successfully...\n", item);
}

// Delete from Front
void deleteAtFirst() {
    if (header == NULL) {
        printf("Empty list. Deletion not possible.\n");
        return;
    }

    struct node *ptr = header;
    header = header->link;
    printf("Deleted element is %d\n", ptr->data);
    free(ptr);
}

// Delete from End
void deleteAtEnd() {
    if (header == NULL) {
        printf("Empty list. Deletion not possible.\n");
        return;
    }

    struct node *ptr = header, *ptr1 = NULL;

    if (header->link == NULL) {   // only one node
        printf("Deleted element is %d\n", header->data);
        free(header);
        header = NULL;
        return;
    }

    while (ptr->link != NULL) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    printf("Deleted element is %d\n", ptr->data);
    ptr1->link = NULL;
    free(ptr);
}

// Delete a node by key
void deleteAtAny(int key) {
    if (header == NULL) {
        printf("Empty list. Deletion not possible.\n");
        return;
    }

    struct node *ptr = header, *ptr1 = NULL;

    while (ptr != NULL && ptr->data != key) {
        ptr1 = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("Key not found, deletion not possible.\n");
        return;
    }

    printf("Deleted element is %d\n", ptr->data);

    if (ptr == header) {          // node to delete is first node
        header = ptr->link;
    } else {
        ptr1->link = ptr->link;
    }

    free(ptr);
}

// Traversing
void traverselist() {
    struct node *ptr = header;
    if (ptr == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main() {
    int choice, key, item;

    do {
        printf("\n\n---------- Single Linked List Menu -----------\n\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert before a key\n");
        printf("4. Delete at front\n");
        printf("5. Delete at end\n");
        printf("6. Delete by key\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert at front: ");
                scanf("%d", &item);
                insertAtFront(item);
                break;

            case 2:
                printf("Enter the element to insert at end: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

            case 3:
                printf("Enter the key: ");
                scanf("%d", &key);
                printf("Enter the element to insert: ");
                scanf("%d", &item);
                insertAtAny(key, item);
                break;

            case 4:
                deleteAtFirst();
                break;

            case 5:
                deleteAtEnd();
                break;

            case 6:
                printf("Enter the key: ");
                scanf("%d", &key);
                deleteAtAny(key);
                break;

            case 7:
                printf("The elements in the list:\n");
                traverselist();
                break;

            case 8:
                printf("Exiting...\n");
                break;

            default:
                printf("Enter a valid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
