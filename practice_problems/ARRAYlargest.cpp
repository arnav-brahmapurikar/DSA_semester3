#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
int A[n];
cin>>n;
for(int i=0;i<n;i++){
    cin>>A[i];
}
int lar=A[0];
for(int i=0;i<n;i++){
    if(A[i]>lar){
        lar=A[i];
    }
}
cout<<lar;
}