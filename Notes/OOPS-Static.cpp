#include<bits/stdc++.h>
using namespace std;


class Customer{
    string name;
    int account_number,balance;
    static int total_customer;
    static int total_balance;
    public:
    Customer(string name,int accNo,int balance){
        this->name=name;
        this->account_number=accNo;
        this->balance=balance;
        total_customer++;
        total_balance+=balance;
    }
    void display(){
        cout<<name<<" "<<account_number<<" "<<balance<<" "<<total_customer; 
    }
    static void aceStatic(){
        cout<<"Total Customer"<<total_customer<<endl;
        cout<<"Total Balance"<<total_balance<<endl;
    }
    void deposit(int amount){
        if(amount>0){
            balance+=amount;
            total_balance+=amount;
        }
        else{
            cout<<"Invalid Entry";
        }
    }
    void withdraw(int amount){
        if(amount<=balance&&amount>0){
            balance-=amount;
            total_balance-=amount;
        }
        else{
            cout<<"Invalid Entry";
        }
    }
};
int Customer::total_customer=0;
int Customer::total_balance=0;
int main(){
    
Customer A1("Rohit",1,1000);
Customer A2("Mohit",2,1000);

Customer A3("MKohit",3,1000);

// A1.display();
A1.deposit(900);
Customer::aceStatic();
Customer A4("MKohit",3,1000);
A2.withdraw(200);
Customer::aceStatic();

}