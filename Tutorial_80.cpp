#include<iostream>
using namespace std;
class Student{
    private:
    string name;

    public:
    void setName(string name){
        this->name=name;
    }
    string getName(){
        return name;
    }

};
int main(){
    Student s1;
    s1.setName("Asad");
    cout<<s1.getName()<<endl;
}