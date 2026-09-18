#include<stdio.h>
#include<stdlib.h>


void reverse(int a[], int n){
    int k;
    int j = n-1;

    for(int i= 0; i< n/2; i++){
            k= a[i];
            a[i]= a[j];
            a[j]= k;
        j--;
    }

    printf("The new array is: \n");
    for(int i= 0; i< n; i++){
        printf("%d ", a[i]);
    }
}

int main(){
    int a[100], n;

    printf("Enter the no of elements: \n");
    scanf("%d", &n);
    printf("Enter the elements: \n");
    for(int i=0; i< n; i++){
        scanf("%d", &a[i]);
    }
    reverse(a, n);
    return 0;

}
