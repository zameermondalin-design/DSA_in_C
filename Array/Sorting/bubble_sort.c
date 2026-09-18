#include<stdio.h>

void bubble_sort(int n, int arr[]){
    for(int i= 0; i<n; i++){
        for(int j= 0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                int k = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = k;
            }
        }
    }

}

int main(){
    int n, arr[50];

    printf("Enter the no of element: ");
    scanf("%d",&n);

    printf("Enter the elements: ");
    for(int i=0; i<n; i++){
        scanf("%d",&arr[i]);
    }

    bubble_sort(n, arr);

    printf("Sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}