#include<stdio.h>
#include<stdlib.h>
#define MAX 6

int front = -1;
int rear = -1;
int Q[MAX];

void enqueue(int val){
    if (rear == MAX-1){
        printf(":: OVERFLOW ::\n");
        return;
    }
    else{
        if(rear == -1 && front == -1){
            rear = 0;
            front = 0;
            Q[rear] = val;
            printf("Inserted\n");
        }
        else{
            rear ++;
            Q[rear] = val;
            printf("Inserted\n");
        }
    }

}

void dequeue(){
    if (front == -1 || front > rear){
        printf(":: UNDERFLOW ::\n");
        return;
    }
    else{
        printf("The deleted value is: %d\n", Q[front]);
        front++;
        if(front > rear) front = rear = -1;
    }

}

void peek(){
    if (front == -1 || front >rear){
        printf(":: EMPTY QUEUE ::\n");
        return;
    }
    else{
        printf("The front/peek element is: %d\n",Q[front]);
    }
}

void display(){
    if (front == -1 || front >rear){
        printf(":: EMPTY QUEUE ::\n");
        return;
    }
    else{
        printf("The queue elements are: \n");
        for (int i = front;i <= rear; i++){
            printf("%d ",Q[i]);
        }
    }
}

int main(){
    int val, choice;
    while(1){
        printf("\n:: MENU ::\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek / Front\n");
        printf("4. Display\n");
        printf("5. Exit\n");

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
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid Input\n");
                break;

        }
    }
    return 0;
}
