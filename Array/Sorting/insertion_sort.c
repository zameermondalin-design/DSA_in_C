#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int n, int arr[]){
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];    
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
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

    insertion_sort(n,arr);

    printf("Sorted array is: ");
    for(int i=0; i<n; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}