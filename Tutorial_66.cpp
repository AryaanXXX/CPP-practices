#include<iostream>
using namespace std;
class student{
    public:
    int id;
    double cgpa;

     student(int x,double y){
        id=x;
        cgpa=y;
    }
    student(){
        cout<<"Default constructor"<<endl;
    }
    void display(){
        cout<<id<<" "<<cgpa<<endl;
    }
};
int main(){
    student ob3;

    student ob(102,3.44);
    cout<<"Details of Arin"<<endl;
    ob.display();

    cout<<"Details of Sara"<<endl;
    student ob1(101,3.50);
    ob1.display();
   
}