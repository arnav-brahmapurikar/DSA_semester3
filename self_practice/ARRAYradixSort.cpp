#include<bits/stdc++.h>
using namespace std;

int getMax(int A[],int n){
    int lar=A[0];
    for(int i=0;i<n;i++){
        if(A[i]>lar){
            lar=A[i];
        }
    }
    return lar;
}
void countSort(int A[],int n,int pos){
    int count[10]={0};
    int B[n];
    for(int i=0;i<n;i++){
       count[(A[i]/pos)%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    for(int i=n-1;i>=0;i++){
        B[count[(A[i]/pos)%10]-1]=A[i];
        count[(A[i]/pos)%10]--;
    }
    for(int i=0;i<n;i++){
        A[i]=B[i];
    }
}

void redixSort(int A[],int n){
    int max=getMax(A,n);
    for(int pos=1; max/pos>0;pos*=10){
        countSort(A,n,pos);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    redixSort(A,n);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<A[i];
    }

}