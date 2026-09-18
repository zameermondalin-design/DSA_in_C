#include<stdio.h>
#include<stdlib.h>

void swapping(int a[], int n,int ind1, int ind2){
    int i= ind1;
    int j= ind2;
    int k;

    k= a[i];
    a[i]= a[j];
    a[j]= k;

    printf("The new array is: \n");
    for(i=0; i< n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int a[100], n, ind1, ind2;

    printf("Enter the no of elements: \n");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(int i=0; i< n; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter the first index: \n");
    scanf("%d", &ind1);
    printf("Enter the second index: \n");
    scanf("%d", &ind2);

    swapping(a, n, ind1, ind2);
    return 0;
}