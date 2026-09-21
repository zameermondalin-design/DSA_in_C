#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert_begining(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if(n == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    n->data = val;
    n->next = head;
    head = n;
}

void insert_ending(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if(n == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    n->data = val;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
        return;
    }

    struct node *ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = n;
}

void insert_middle(int val, int pos)
{
    if(pos <= 0)
    {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1)
    {
        insert_begining(val);
        return;
    }

    if(head == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    struct node *n = (struct node*)malloc(sizeof(struct node));

    if(n == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    n->data = val;
    n->next = NULL;

    struct node *ptr = head;
    int i = 1;

    while(i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL)
    {
        printf("Invalid Position\n");
        free(n);
        return;
    }

    n->next = ptr->next;
    ptr->next = n;
}


void creation()
{
    int val, choice = 1;
    struct node *ptr = NULL;

    while (choice)
    {
        printf("Enter value: ");
        scanf("%d", &val);

        struct node *n = (struct node *)malloc(sizeof(struct node));

        n->data = val;
        n->next = NULL;

        if (head == NULL)
        {
            head = n;
            ptr = n;
        }
        else
        {
            ptr->next = n;
            ptr = n;
        }

        printf("Add more? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    }
}

void display()
{
    if (head == NULL)
    {
        printf("Empty List\n");
        return;
    }

    struct node *ptr = head;

    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

void free_list()
{
    struct node *temp;

    while(head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int choice, val, pos;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Create List\n");
        printf("2. Insert Beginning\n");
        printf("3. Insert End\n");
        printf("4. Insert Middle\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            creation();
            break;

        case 2:
            printf("Enter value: ");
            scanf("%d", &val);
            insert_begining(val);
            break;

        case 3:
            printf("Enter value: ");
            scanf("%d", &val);
            insert_ending(val);
            break;

        case 4:
            printf("Enter value and position: ");
            scanf("%d %d", &val, &pos);
            insert_middle(val, pos);
            break;

        case 5:
            display();
            break;

        case 6:
            free_list(); 
            printf("Program Terminated\n");
            return 0;

        default:
            printf("Invalid Choice\n");
        }
    }
    
    return 0;
}