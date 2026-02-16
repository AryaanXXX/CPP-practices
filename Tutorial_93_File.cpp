#include<iostream>
#include<fstream>
using namespace std;
int main(){
    string name;
    ofstream file; //write file
    file.open("Student.txt");
    cout<<"Enter your name:"<<endl;
    //getline(cin,name);
    cin>>name;
    file.close();
    //cout<<"Data is stored"<<endl;
}