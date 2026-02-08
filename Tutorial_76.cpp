#include<iostream>
using namespace std;
class University{
    public:
    const int addmissionfee;
    const int examfee;

    University(int x,int y)
    :addmissionfee(x),examfee(y){
        cout<<addmissionfee<<endl;
        cout<<examfee<<endl;
    }
};
int main(){
    University ob(15000,500);
}