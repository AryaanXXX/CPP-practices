#include<iostream>
using namespace std;
class Mobileuser{
    public:
    virtual void sendMessage()=0;
    void call(){
        cout<<"Hello "<<endl;
    }
};
class Rohim : public Mobileuser{
    public:
    void sendMessage(){
        cout<<"This is Rohim "<<endl;
    }
};
class korim : public Mobileuser{
    public:
    void sendMessage(){
        cout<<"This is Korim "<<endl;
    }
};
int main(){
    Mobileuser *m;
    Rohim r;
    korim k;

    m=&r;
    m->call();
    m->sendMessage();
    m=&k;
    m->sendMessage();
//calling with own classes object
    r.sendMessage();
}