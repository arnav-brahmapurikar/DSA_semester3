#include<bits/stdc++.h>
using namespace std;


//OPTIMAL

vector<int>findArrayIntersection(vector<int>&A,int n,vector<int>&B,int m){
    int i=0;
    int j=0;
    vector<int>ans;
    while(i<n && j<m){
        if(A[i]<B[j]){
            i++;
        }
        else if(A[i]>B[j]){
            j++;
        }
        else{
            ans.push_back(A[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    
}