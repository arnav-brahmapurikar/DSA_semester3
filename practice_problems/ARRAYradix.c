#include<stdio.h>
int GetMaxNum(int A[],int n){
        int lar=A[0]; 
    for(int i=0;i<n;i++){
        if(A[i]>lar){
            lar=A[i];
        }
    }
    int count=0;
    while(lar>0){
        count++;
        lar=lar/10;
    }
    return count;
}

void countSort(int A[],int n,int pos){
    int count[10];
    int output[n];
    for(int i=0;i<n;i++){
        count[(A[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        A[count[(A[i]/pos)%10]--]=A[i];
        count[(A[i]/pos%10)]--;
    }
    for(int i=0;i<n;i++){
        A[i]=output[i];
    }
}

void RadixSort(int A[],int n){
    int l=GetMaxNum(A,n);

    for(int pos=0;pos<l/pos;pos*10){
        countSort(A,n,pos);
    }
}