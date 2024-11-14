#include<bits/stdc++.h>
using namespace std;
class Rectangle{
    private:
    int length;
    int width;

    public:
    Rectangle(int l,int b){
        this->length=l;
        this->width=b;
    }
    int area(int l,int b){
        return length*width;
    }
    int perimeter(int l,int b){
        return 2*(length+width);
    }
};
int main(){
    int l,b;
    cin>>l;
    cin>>b;
    Rectangle R(l,b);
    int Rarea=R.area(l,b);
    cout<<Rarea;
    cout<<endl;
    int Peri=R.perimeter(l,b);
    cout<<Peri;
    return 0;
}