#include<stdio.h>
#include<stdlib.h>

int cmp (const void * a,const void *b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int arr[] = {-1, 9, -2, 4, 6, 2, 0, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
    qsort(arr, n, sizeof(int), cmp);
    for(int i = 0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}