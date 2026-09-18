#include<stdio.h>

void selection_sort(int n, int arr[]){
    for(int i= 0; i<n; i++){
        int min = i;

        for(int j= i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
            int k = arr[min];
            arr[min] = arr[i];
            arr[i] = k;
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

    selection_sort(n,arr);

    printf("Sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}