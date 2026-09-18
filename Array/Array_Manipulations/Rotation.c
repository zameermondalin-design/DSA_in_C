#include<stdio.h>
#include<stdlib.h>

void reverse(int a[], int start, int end){
    int k;
    while(start < end){
        k = a[start];
        a[start] = a[end];
        a[end] = k;
        start++;
        end--;
    }
}

int main(){
    int a[100], n, d;

    printf("Enter number of elements: \n");
    scanf("%d", &n);

    printf("Enter elements: \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter rotation count: \n");
    scanf("%d", &d);

    d = d % n;

    reverse(a, 0, d - 1);
    reverse(a, d, n - 1);
    reverse(a, 0, n - 1);

    printf("Rotated array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}