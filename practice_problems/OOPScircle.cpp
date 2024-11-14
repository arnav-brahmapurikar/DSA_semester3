#include<bits/stdc++.h>
using namespace std;

    const int pi=3.14;
    class Circle{
        private:
        int radius;

        public:
        Circle(int r){
            this->radius=r;
        }
        float area(int r){
            return pi*r*r;  
        }
        float circumference(int r){
            return 2*pi*r;
        }

    };
int main(){
    int n;
    cin>>n;
    Circle C(n);
    int Carea=C.area(n);
    cout<<Carea;
    cout<<endl;
    int Ccircum=C.circumference(n);
    cout<<Ccircum;
    return 0;
}