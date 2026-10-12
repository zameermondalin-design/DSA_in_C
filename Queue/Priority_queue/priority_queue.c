
#include <stdio.h>
#define MAX 100

struct node {
    int data;
    int priority;
};

struct node pq[MAX];
int size = 0;

void enqueue(int val, int p)
{
    if (size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }

    int i = size - 1;

    while (i >= 0 && pq[i].priority > p) {
        pq[i + 1] = pq[i];
        i--;
    }

    pq[i + 1].data = val;
    pq[i + 1].priority = p;
    size++;

    printf("Element inserted successfully\n");
}

void dequeue()
{
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", pq[0].data);

    for (int i = 0; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
}

void display()
{
    if (size == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Data\tPriority\n");

    for (int i = 0; i < size; i++) {
        printf("%d\t%d\n", pq[i].data, pq[i].priority);
    }
}

int main()
{
    int choice, val, p;

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &val);

                printf("Enter priority: ");
                scanf("%d", &p);

                enqueue(val, p);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
