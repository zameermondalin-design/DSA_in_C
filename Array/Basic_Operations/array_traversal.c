#include<stdio.h>

void traverse(int a[], int n){

    for(int i= 0; i< n; i++){
    printf("%d ", a[i]);
    }

}

int main(){
    int n, index, k;
    int a[100];
    printf("Enter the no of element: \n");
    scanf("%d",&n);

    printf("Enter the elements: \n");
    for(int i= 0; i<n; i++){
    scanf("%d",&a[i]);
    }

    traverse(a,n);

    return 0;
}