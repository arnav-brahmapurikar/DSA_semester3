#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int A[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && A[left]>A[largest]){
        largest=left;
    }
    if(right<n && A[right]>A[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&A[largest],&A[i]);
        heapify(A,n,largest);
    }
}
void BuildMaxHeap(int A[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(A,n,i);
    }
}
void HeapSort(int A[],int n){
    BuildMaxHeap(A,n);
    for(int i=n-1;i>=0;i--){
        swap(&A[0],&A[i]);
        heapify(A,i,0);
    }
}
void PrintArray(int A[],int n){
    for(int i=0;i<n;i++){
        
    }
}