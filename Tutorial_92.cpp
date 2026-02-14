#include<iostream>
using namespace std;
int main(){
    try{
    int num1,num2;
    cout<<"Enter num1 : "<<endl;
    cin>>num1;
    cout<<"Enter num2: "<<endl;
    cin>>num2;
    if(num2==0){
        throw -1;
    }
    double result=(double)num1/num2;
    cout<<"The result is "<<result<<endl;
    }catch(...){
        cout<<"Divide by zero is not possible "<<endl;
    }
}