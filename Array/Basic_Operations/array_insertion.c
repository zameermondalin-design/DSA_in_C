#include<stdio.h>
#include<stdlib.h>

void insertion(int a[], int n, int index, int k){
    int i, j;
    i= n;
    j= n-1;

    while(1){
        if(i== index){
            a[i]= k;
            printf(":::Insertion Sucessful:::\n");
            n++;
            break;
        }
        else{
            a[i] = a[j];
            i--;
            j--;
        }
    }
        
    printf("The new array is: \n");
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
        
    printf("Which index are you want to insert: \n");
    scanf("%d",&index);
    printf("Enter the element: \n");
    scanf("%d",&k);

    insertion(a,n,index,k);

    return 0;

}