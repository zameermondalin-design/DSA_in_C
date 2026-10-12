#include<stdio.h>
#define STACK_SIZE 20
int stack[STACK_SIZE];
int top = -1;

void push(int val){
    
    if(top== STACK_SIZE-1){
        printf("overflow");
        return;
    }
    else{
        top++;
        stack[top]= val;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is empty");
        return;
    }
    printf("The poped element is: %d", stack[top]);
    top--;
}

void peek(){
    if(top == -1){
        printf("Stack is empty");
        return;
    }
    printf("The peek element is: %d", stack[top]);
}

void display(){\
    if(top == -1){
        printf("Stack is empty");
        return;
    }
    printf("The stacked elements are: \n");
    for(int i= 0; i< top; i++){
        printf("%d ", stack[i]);
    }
}

int main(){
    int val;

while(1){
        printf("\n::: Stack :::");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Display");
        printf("\n5. Exit");

        int choice;
        printf("\nEnter your choice: ");
        scanf(" %d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the value: ");
                scanf("%d",&val);
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
                printf("Invalid input");
                break;
    }
}
    return 0;
}