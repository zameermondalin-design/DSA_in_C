#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};

struct node *head = NULL;

void insert_beginning(int data)
{
    struct node *newnode, *last;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;

        head = newnode;
    }
}

void insert_end(int data)
{
    struct node *newnode, *last;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    if(head == NULL)
    {
        newnode->next = newnode;
        newnode->prev = newnode;
        head = newnode;
    }
    else
    {
        last = head->prev;

        newnode->next = head;
        newnode->prev = last;

        last->next = newnode;
        head->prev = newnode;
    }
}

void insert_middle(int data, int pos)
{
    struct node *newnode, *temp;
    int i;

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;

    temp = head;

    for(i = 1; i < pos; i++)
        temp = temp->next;

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}

void delete_beginning()
{
    struct node *temp, *last;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head->prev;

    head = head->next;

    head->prev = last;
    last->next = head;

    free(temp);
}

void delete_end()
{
    struct node *last, *secondLast;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    last = head->prev;
    secondLast = last->prev;

    secondLast->next = head;
    head->prev = secondLast;

    free(last);
}

void delete_middle(int pos)
{
    struct node *temp;
    int i;

    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if(pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    for(i = 1; i < pos; i++)
        temp = temp->next;

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void creation(){
    struct node *ptr;
    int val, choice=1;

    while(choice) {
        printf("Enter value: ");
        scanf("%d", &val);

        struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->next = NULL;
        n->prev = NULL;

        if(head == NULL) {
            head = n;
            ptr = n;
        } else {
            ptr->next = n;
            n->prev = ptr;
            ptr = n;
        }

        printf("Add more? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    }
}

void display(){
    if(head==NULL){
        printf("Empty list");
        return;
    }
    struct node *ptr;
    ptr=head;

    while(ptr!=NULL){
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");

}

int main(){
    while(1){
    printf(":: Menu ::");
    printf("1. Create List");
    printf("2. Insert Begining");
    printf("3. Insert End");
    printf("4. Insert Middle");
    printf("5. Delete Begining");
    printf("6. Delete Ending");
    printf("7. Delete Middle");
    printf("8. Display");
    printf("9. Exit");

    int choice;
    printf("Enter the choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            creation();
            break;
        case 2:
            int val;
            printf("Enter the value: ");
            scanf("%d",&val);
            insert_begining(val);
            break;
        case 3:
            int val;
            printf("Enter the value: ");
            scanf("%d",&val);
            insert_ending(val);
            break;
        case 4:
            int val, pos;
            printf("Enter the value & position: ");
            scanf("%d %d",&val,&pos);
            insert_middle(val,pos);
            break;
        case 5:
            deletion_begining();
            break;
        case 6:
            deletion_ending();
            break;
        case 7:
            int pos;
            printf("Enter the position: ");
            scanf("%d",&pos);
            deletion_middle(pos);
            break;
        case 8:
            display();
            break;
        case 9:
            return 0;
        default:
            printf("Invalid input");
        }
    }   

    return 0;
}