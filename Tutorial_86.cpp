#include<iostream>
using namespace std;
class Person{
    public:
    virtual void display(){    //sobai jate use korte pare ty etike virtual kore dite hobe.
        cout<<"I am a person"<<endl;
    }
};
class Student : public Person{
    public:
    void display(){
        cout<<"I am a Student "<<endl;
    }
};
class teacher : public Person{
    public:
    void display(){
        cout<<"I am a teacher "<<endl;
    }
};

int main(){
    Student s;
    teacher t;
    Person *p;  //super class
    p=&s;
    p->display();

    p=&t;
    p->display();    
}