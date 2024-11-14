// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n,A[n];
//     cin>>n;
//     for(int i;i<n;i++){
//         cin>>A[i];
//     }
// set<int>st;
// for(int i=0;i<n;i++){
//     st.insert(A[i]);
// }
// int index=0;
// for(auto it:st){
//     A[index]=it;
//     index++;
// }
// cout<<"Size of Array is: "<<index<<endl;

// for(auto it:st){
//     cout<<it;
// }
// }





// M2



#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,A[n];
    cin>>n;
    for(int i;i<n;i++){
        cin>>A[i];
    }


    int k=0;
        for(int j;j<n;j++){
            if(A[j]!=A[k]){
                A[k+1]=A[j];
                k++;
            }
        }
        int p= k+1;
        cout<<p<<endl;
    for(int j;j<p;j++){
        cout<< A[j];
    }
    
}
