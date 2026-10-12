#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int front = -1, rear = -1;
int DQ[MAX];

void insert_front(int val){
    if(front == 0){
        printf(":: OVERFLOW ::\n");
        return;
    }
    else{ 
        if(front == -1 && rear == -1){
            front = rear = 0;
            DQ[front] = val;
            printf("Inserted");
        }
        else{
            front--;
            DQ[front] = val;
            printf("Inserted");
        }
    }
}

void enqueue(int val){
    if(rear == MAX-1){
        printf(":: OVERFLOW ::\n");
        return;
    }
    else{
        if(rear == -1 && front == -1){
            front = rear = 0;
            DQ[rear] = val;
            printf("Inserted\n");
        }
        else{
            rear++;
            DQ[rear] = val;
            printf("Inserted\n");
        }
    }
}

void dequeue(){
    if(front == -1||front > rear){
        printf(":: UNDERFLOW ::\n");
        return;
    }
    else{
        printf("The deleted value is: %d\n", DQ[front]);
        front++;
        if(front > rear) front = rear = -1;
    }
}

void delete_rear(){
    if(rear == -1||front > rear){
        printf(":: UNDERFLOW ::\n");
        return;
    }
    else{
        printf("The deleted value is: %d\n", DQ[rear]);
        rear--;
        if(front > rear) front = rear = -1;
    }
}

void display(){
    if (rear == -1 || front > rear){
        printf(":: Empty Deque ::\n");
        return;
    }
    else{
        printf("The deque elements are: \n");
        for (int i=front; i<=rear; i++){
            printf("%d ",DQ[i]);
        }
    }
}

int main(){
    int val,choice;
    while(1){
        printf("\n:: MENU ::\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Insert_front\n");
        printf("4. Delete_rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        
        printf("Enter the choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d",&val);
                insert_front(val);
                break;
            case 4:
                delete_rear();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
            default:
                printf("Invalid input");
                break;
        }
    }
    return 0;
}