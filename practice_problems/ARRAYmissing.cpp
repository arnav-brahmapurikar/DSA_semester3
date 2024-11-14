#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int A[n];
    for(int i=0;i<n;i++){
    cin>>A[i];
    }
    int hash[n+1]={0};
    for(int i=0;i<n;i++){
        hash[A[i]]=1;
    }
    for(int i=1;i<n;i++){
        if(hash[A[i]]==0){
            cout<< A[i];
        }
    }
}