#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node * creation(int val){
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = val;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

void enqueue_rear(int val){
    struct node *temp = creation(val);
    if(front == NULL){
        rear = temp;
        front = temp;
        return;
    }
    else{
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
    }
}

void enqueue_front(int val){
    struct node *temp = creation(val);
    if(front == NULL){
        rear = temp;
        front = temp;
        return;
    }
    else{
        front->prev = temp;
        temp->next = front;
        front = temp;
    }
}

void dequeue_front(){
    if(front == NULL){
        printf("The deque is empty.\n");
        return;
    }
    else{
        printf("The deleted value is: %d", front->data);
        struct node *temp = front;
        if(front->next == NULL){
            front = rear= NULL;
        }
        else{
            front = temp->next;
            front->prev = NULL;
        }
        free(temp);
    }
    return;
}

void dequeue_rear(){
    if(front == NULL){
        printf("The deque is empty.\n");
        return;
    }
    else{
        printf("The deleted value is: %d", rear->data);
        struct node *temp = rear;
        if(rear->prev == NULL){
            front = rear= NULL;
        }
        else{
            rear = temp->prev;
            rear->next = NULL;
        }
        free(temp);
    }
    return;
}

void display(){
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

int main(){
    int choice, val;
    while(1){
            printf(":::Choices:::\n");
            printf("1. Enqueue_rear\n");
            printf("2. Enqueue_front\n");
            printf("3. Dequeue_front\n");
            printf("4. Dequeue_rear\n");
            printf("5. Display\n");
            printf("6. Exit\n");
            printf("Enter your choice:\n");
            scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value:\n");
                scanf("%d",&val);
                enqueue_rear(val);
                break;
            case 2:
                printf("Enter the value:\n");
                scanf("%d",&val);
                enqueue_front(val);
                break;
            case 3:
                dequeue_front();
                break;
            case 4:
                dequeue_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
    }
    return 0;
}


