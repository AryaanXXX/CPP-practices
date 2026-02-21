#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string name;
    int age;
    ofstream file;
    file.open("Student details.txt",ios::out|ios::app);
    for(int i=0; i<=1; i++){
    cout<<"Enter your name:"<<endl;
    cin>>name;
    //getline(cin,name);
    //gets(name);
    file<<name<<endl;
    cout<<"Enter your age:"<<endl;
    cin>>age;
    file<<age<<endl;
    //cin.ignore();   //not mendatory 

    }
    file.close();
}