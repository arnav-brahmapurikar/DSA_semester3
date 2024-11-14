#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter by size of Array";
    cin>> n;
    int A[n];
    for (int i=0;i<n;i++){
        cin>> A[i];
    }
    int d;
    cout<<"Enter by how much u want to rotate";
    cin>> d;
    int temp[d];
    int p=0;
    for (int k=0;k<d;k++){
        temp[k]=A[p];
        p++;
    }
    
    for(int i=d;i<n;i++){
        if(A[i-d]=A[i]);
    }
    int j=0;
    for(int i=n-d;i<n;i++){
        A[i]=temp[j];
        j++;
    }
    for (int i=0;i<n;i++){
        cout<< A[i];
    }
    return 0;
}