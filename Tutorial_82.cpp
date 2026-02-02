#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;
    Person(string name,int age){
        this->name=name;
        this->age=age;
    }
    void display1(){
        cout<<name<<endl;
        cout<<age<<endl;
    }
};
class Student:public Person{
    public:
    int id;    //name,age cuz we just inherit person class;
   Student(string name,int age,int id):Person(name,age){
    this->id=id;
   }
    void display2(){
        cout<<id<<endl;
        display1();
    }
};
int main(){
    Student ob("Asad",20,101);
    ob.display2();
}