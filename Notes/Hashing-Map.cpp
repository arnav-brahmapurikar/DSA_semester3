#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    //pre-computation
    map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[A[i]]++;
    }

for(auto it : mpp){
cout<<it.first<<"->"<<it.second<<endl;
}

    //fetch
    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<mpp[number]<<endl;
    }

    return 0;
}