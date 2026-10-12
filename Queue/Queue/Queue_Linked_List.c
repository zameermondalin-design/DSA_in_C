#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }

    n->data = val;
    n->next = NULL;

    if (front == NULL)
    {
        front = rear = n;
    }
    else
    {
        rear->next = n;
        rear = n;
    }

    printf("Inserted Successfully\n");
}

void dequeue()
{
    if (front == NULL)
    {
        printf(":: UNDERFLOW ::\n");
        return;
    }

    struct node *temp = front;

    printf("Deleted element: %d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void peek()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Front element: %d\n", front->data);
}


void display()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = front;

    printf("Queue elements: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, val;

    while (1)
    {
        printf("\n===== QUEUE USING LINKED LIST =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}