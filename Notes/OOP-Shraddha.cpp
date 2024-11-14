#include<bits/stdc++.h>
using namespace std;

class Teacher{
    private:
    double salary;
    public:
    string name;
    string dept;
    string subject;
    void GetInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Subject: "<<subject<<endl;
    }

// USING PRIVATE IN MAIN
    void changeDept(string newDept){
        dept=newDept;
    }
        // setter
    void setSalary(double s){
        salary=s;
    }
        // getter
    double getSalary(){
        return salary;
    }


// CONSTRUCTER
    Teacher(string name,string dept,string subject, double salary){
        this->name=name;
        this->dept=dept;
        this->subject=subject;
        this->salary=salary;
    }
// COPY CONSTRUCTOR        
    Teacher(Teacher &OrgObj){
        cout<<"This is Custom CC"<<endl;
        this->name=OrgObj.name;
        this->dept=OrgObj.dept;
        this->subject=OrgObj.subject;
        this->salary=OrgObj.salary;
    }
  
};
//Shallow CC
 // Problem during Dynamic Memory Allocation
class Student{
        public: 
        string name;
        double* cgpaPtr;

    Student(string name,double cgpa){
        this->name=name;
        cgpaPtr=new double;
        *cgpaPtr=cgpa;

    }  
    Student(Student &OrgObj){
        cout<<"This is Custom CC"<<endl;
        this->name=OrgObj.name;
        cgpaPtr=new double;    //DEEP COPY
        *cgpaPtr=*OrgObj.cgpaPtr;
    }
    void GetInfo2(){
        cout<<"Name: "<<name<<endl;
        cout<<"CGPA: "<<cgpaPtr<<endl;
    }
        
};
int main(){
Teacher T1("Shresth","CS","OOPS",250000);
T1.GetInfo();
Teacher T2(T1);//Copy Constructer
T2.GetInfo();

cout<<endl;
cout<<endl;
Student s1("Shresth",9.2);
s1.GetInfo2();
cout<<endl;
Student s2(s1);
s1.GetInfo2();
*(s2.cgpaPtr)=9.2;
s1.GetInfo2();
return 0;
}