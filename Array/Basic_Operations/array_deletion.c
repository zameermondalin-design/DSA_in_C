#include<stdio.h>
#include<stdlib.h>

void deletion(int a[], int n, int index){
    int i, j;

    if(index >= 0 && index < n){
        for(i=index;i<n;i++){
            j= i+1;
            a[i]= a[j];
        }
        printf("::Deletion Sucessful::\n");
    }
    else{
        printf("::Invalid Index::\n");
    }
        
    printf("The new array is: \n");
    for(int i= 0; i< n-1; i++){
    printf("%d ", a[i]);
    }

}

int main(){
    int n, index;
    int a[100];
    printf("Enter the no of element: \n");
    scanf("%d",&n);

    printf("Enter the elements: \n");
    for(int i= 0; i<n; i++){
    scanf("%d",&a[i]);
    }
        
    printf("Which index are you want to delete: \n");
    scanf("%d",&index);

    deletion(a,n,index);

    return 0;

}