#include<iostream>
using namespace std;
void addition(int a,int b){
    int sum=a+b;
    cout<<"Sum is ="<<sum<<endl;
}

void subttraction(int a,int b){
    int result=a-b;
    cout<<"The subtraction is ="<<result<<endl;
}

void multiplication(int a,int b){
    int mul=a*b;
    cout<<"The multiplication is ="<<mul<<endl;
}

void division(int a,int b){
    float result=(float)a/b;  //did type casting
    cout<<"The division is="<<result<<endl;
}
int main(){
    addition(10,3);
    subttraction(10,3);
    multiplication(10,3);
    division(10,3);

    cout<<"All function have called";
    
}
