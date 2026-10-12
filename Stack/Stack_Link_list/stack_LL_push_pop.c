#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val){

    struct Node* newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = top;

    top = newNode;

    printf("Inserted: %d\n", val);
}

void pop(){

    if(top == NULL){
        printf("Stack Underflow\n");
        return;
    }

    struct Node* temp;

    temp = top;

    printf("Deleted element: %d\n", top->data);

    top = top->next;

    free(temp);
}

void peek(){

    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", top->data);
}

void display(){

    if(top == NULL){
        printf("Stack is empty\n");
        return;
    }

    struct Node* temp;

    temp = top;

    printf("Stack elements are:\n");

    while(temp != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main(){

    int choice, val;

    while(1){

        printf("\n::: STACK USING LINKED LIST :::");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}