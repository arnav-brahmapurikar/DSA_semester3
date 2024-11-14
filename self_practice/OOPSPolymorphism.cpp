#include<bits/stdc++.h>
using namespace std;

class Complex
{
    int real,img;
    public:
    Complex(){}
    Complex(int real,int img){
        this->img=img;
        this->real=real;
    }
    void display(){
        cout<<real<<" +i"<<img<<endl;
    } 
    Complex operator +(Complex &C){
        Complex ans;
        ans.real=real+C.real;
        ans.img=img+C.img;
        return ans;
    }
};
int main(){

    Complex c1(3,4);
    Complex c2(5,6);
    Complex c3=c1+c2;
    c3.display();
}