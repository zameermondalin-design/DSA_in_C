#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node *next;
   struct node *prev;
};

struct node *head = NULL;

void insert_begining(int val){
    struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->next = NULL;
        n->prev = NULL;

    if(head  == NULL){
        head = n;
    }
    else{
        n->next = head;
        head->prev = n;
        head = n;
    }
}

void insert_ending(int val){
    struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->next = NULL;
        n->prev = NULL;

    struct node *ptr = head;

    if(head == NULL){
        head = n;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = n;
        n->prev = ptr;
    }
}

void insert_middle(int val, int pos){
    struct node *n = (struct node*)malloc(sizeof(struct node));
        n->data = val;
        n->next = NULL;
        n->prev = NULL;

    int i=1;
    struct node *ptr = head;

    if(head == NULL){
        head = n;
    }
    else{
        while(i<pos-1 && ptr->next != NULL){
            ptr = ptr->next;
            i++;
        }
        n->next = ptr->next;
        ptr->next->prev = n;
        ptr->next = n;
        n->prev = ptr;

    }

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
    printf("2. Insert Begining");
    printf("3. Insert End");
    printf("4. Insert Middle");
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

