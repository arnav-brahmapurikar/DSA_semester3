//SELECTION SORT: Takes Minimum to the front.

//BUBBLE SORT: Takes Maximum to the last by adjacent swapping.

//INSERTION SORT: Takes an element and places it in its correct position.Apne peeche k sabb sort krta jaata hai



#include<bits/stdc++.h>
using namespace std;
void selection(int A[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i;j<n;j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        int temp=A[min];
        A[min]=A[i];
        A[i]=temp;
            
    }
}
void bubble(int A[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]){
                swap(A[j],A[j+1]);
            }
        }

    }
}

void insertion(int A[],int n){
    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && A[j-1]>A[j]){
            swap(A[j],A[j-1]);
            j--;
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

    // selection(A,n);

    // bubble(A,n);

    // insertion(A,n);

    

    for(int i=0;i<n;i++){
        cout<<" "<<A[i];
    }
    return 0;
}