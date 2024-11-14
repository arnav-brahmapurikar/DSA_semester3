// #include<bits/stdc++.h>
// using namespace std;
// int main(){
// int n;

// int A[n];
// cin>>n;
// for(int i=0;i<n;i++){
//     cin>>A[i];
// }
// int lar=A[0];
// for(int i=0;i<n;i++){
//     if(A[i]>lar){
//         lar=A[i];
//     }
// }
// cout<<lar;
// // cout<<endl;
// sort(A,A+n);
// int secL=-1;
// for(int i=n-2;i>=0;i++){
//     if(A[i]!=lar){
//         secL=A[i];
//         break;
//     }
// }
// cout<<secL<<endl;
// }

// TIME COMPLEXITY = LOG(N)+N
// BETTER APPROACH:-

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
int sLar=-1;
for(int i=0;i<n;i++){
    if(A[i]>sLar && A[i]!=lar){
        sLar=A[i];
    }
}
cout<<sLar<<endl;
}