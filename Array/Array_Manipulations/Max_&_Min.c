#include<stdio.h>
#include<stdlib.h>

int Max(int a[], int n){
    int max= 0;
    for(int i=0; i< n; i++){
        if(a[i] > max) max= a[i];
    }
    return max;
}

int Min(int a[], int n){
    int min = Max(a,n);
    for(int i=0; i< n; i++){
        if(a[i] < min) min= a[i];
    }
    return min;
}

int main(){
    int a[100], n;

    printf("Enter the no of elements: \n");
    scanf("%d",&n);

    printf("Enter the elements: \n");
    for(int i= 0; i<n; i++){
    scanf("%d",&a[i]);
    }

    int max= Max(a,n);
    int min= Min(a,n);

    printf("The largest element is: %d", max);
    printf("The smallest element is: %d", min);
    return 0;
}