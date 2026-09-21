#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};

struct node *head = NULL;

void deletion_begining(){
    struct node *ptr = head;

    if(head == NULL){
        printf("Error: Empty LIst !!");
    }
    else{
        head = ptr->next;
        free(ptr);
    }
}

void deletion_ending(){
    struct node *ptr = head;
    struct node *temp;

    if(head == NULL){
        printf("Error: Empty LIst !!");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }  
    else{
        while(ptr->next->next != NULL){
            ptr = ptr->next;
        }
        temp = ptr->next;
        ptr->next = NULL;
        free(temp);

    }

}

void deletion_middle(int pos){
    int i = 1;
    struct node *ptr = head;
    struct node *temp;

    if(head == NULL){
        printf("Error: Empty List !!");
        return;
    }

    while(i < pos-1 && ptr != NULL){
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL || ptr->next == NULL){
        printf("Invalid Position");
        return;
    }

    temp = ptr->next;
    ptr->next = temp->next;
    free(temp);
}

void insert(){
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
    printf("2. Delete Begining");
    printf("3. Delete Ending");
    printf("4. Delete Middle");
    printf("5. Display");
    printf("6. Exit");

    int choice;
    printf("Enter the choice: ");
    scanf("%d",&choice);

    switch(choice){
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
            int pos;
            printf("Enter the position: ");
            scanf("%d",&pos);
            deletion_middle(pos);
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input");
        }
    }   

    return 0;
}

