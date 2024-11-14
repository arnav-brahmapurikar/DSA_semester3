#include<bits/stdc++.h>
using namespace std;
class person{
    public:
    string name;
    int age;
    
    person(){

    }
};


class student :public person{
    public:
    int rollNo;

    void getInfo(){
        cout<<"age: "<<age<<endl;
        cout<<"name: "<<name<<endl;
        cout<<"rollNo: "<<rollNo<<endl;
    }
};

int main(){
    student s1;
    s1.name="Shresth";
    s1.age=24;
    s1.rollNo=1234;

    s1.getInfo();
    return 0;
}