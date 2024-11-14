//Character Hashing


#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cout<<"Enter the string: ";
    cin>> str;
    //all the letter are small
    int hash[26]={0};
    for(int i=0;i<str.size();i++){
        hash[str[i]-'a']++;
    }
     int q;
    cout<<"Enter the Test Case";
    cin>>q;
    while(q--){
        char c;
        cin>> c;
        cout<< hash[c-'a']<< endl;
    }
//if it doesn't state about the exclutivity of the characters you have to take hash[256]

//In that case code will be:-
int hash[256]={0};
    for(int i=0;i<str.size();i++){
        hash[str[i]]++;
    }
    int q;
    cout<<"Enter the Test Case";
    cin>>q;
    while(q--){
        char c;
        cin>> c;
        cout<< hash[c]<< endl;
    }
return 0;
}