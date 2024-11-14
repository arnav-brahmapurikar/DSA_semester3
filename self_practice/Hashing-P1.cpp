//Count elements of Array

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>> n;
    int A[n];
    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    //pre-compute
    int hash[20]={0};
    for(int i=0;i<n;i++){
        hash[A[i]]+=1;
    }


    //fetch
    int q;
    cout<<"Enter test case";
    cin>>q;
    while(q--){
        int num;
        cout<<"Enter the Number to be searched";
        cin>>num;
        cout<<"count of number= "<< hash[num]<<endl;
    }
    return 0;
    
}