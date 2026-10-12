#include <stdio.h>

int MAX;
int queue[50];
int front = -1, rear = -1;

void enqueue(int item)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Queue Overflow\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = item;
    printf("%d inserted successfully\n", item);
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }

    printf("Deleted Element = %d\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;

    printf("Queue Elements: ");

    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }

    printf("%d\n", queue[rear]);
}

int main()
{
    int choice, val;

    printf("Enter the size of Circular Queue (Max 50): ");
    scanf("%d", &MAX);

    if (MAX <= 0 || MAX > 50)
    {
        printf("Invalid Queue Size\n");
        return 0;
    }

    while (1)
    {
        printf("\n===== CIRCULAR QUEUE MENU =====\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &val);
            enqueue(val);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            printf("Program Terminated\n");
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }

    return 0;
}