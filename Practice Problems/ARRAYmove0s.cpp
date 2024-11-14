#include<bits/stdc++.h>
using namespace std;
void print(int A[],int n){
    for(int i=0;i<n;i++){
        cout<<" "<<A[i];
    }
}

//BRUTE FORCE 

void brute(int A[],int n){
    int nz;
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            nz++;
        }
    }
    int temp[nz];
    int k=0;
    for(int i=0;i<n;i++){
        if(A[i]!=0){
            while(k<nz){
            temp[k]=A[i];
            k++;
            }
        }
    }
    for(int i=0;i<nz;i++){
        A[i]=temp[i];
    }
    
    for(int i=nz;i<n;i++){
        A[i]=0;
    }
    cout<<endl;
    print(A,n);
}

void optimal(int A[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(A[i]==0){
            j=i;
            break;
        }
    }
    for(int i=j+1;i<n;i++){
        if(A[i]!=0){
            swap(A[i],A[j]);
            j++;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    brute(A,n);

}