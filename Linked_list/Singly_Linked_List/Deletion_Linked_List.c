#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void deletion_begining()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    struct node *ptr = head;
    head = head->next;
    free(ptr);
}

void deletion_ending()
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        return;
    }

    struct node *ptr = head;

    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }

    free(ptr->next);
}

void deletion_middle(int pos)
{
    if (head == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    if (pos == 1)
    {
        deletion_begining();
        return;
    }

    struct node *ptr = head;
    int i = 1;

    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL || ptr->next == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    struct node *temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
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
    int choice, pos;

    while (1)
    {
        printf("\n===== MENU =====\n");
        printf("1. Create List\n");
        printf("2. Delete Beginning\n");
        printf("3. Delete Ending\n");
        printf("4. Delete Middle\n");
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
            deletion_begining();
            break;

        case 3:
            deletion_ending();
            break;

        case 4:
            printf("Enter position: ");
            scanf("%d", &pos);
            deletion_middle(pos);
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