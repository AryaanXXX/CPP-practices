#include<iostream>
using namespace std;
int main(){
    while(1){
        int GuessNumber,randomNumber;
    cout<<"Enter your guess between 1 to 5:";
    cin>>GuessNumber;
    randomNumber=rand()%5+1;   //this 0 hole 1 hobe and 1 hole 2 hobe ultime 5 porjontw num nibe.
    if(GuessNumber==randomNumber){
        cout<<"You won the game "<<endl<<endl;
    }
    else{
        cout<<"You have lost. try again "<<endl<<endl;
        cout<<"RandomNumber was:"<<randomNumber<<endl<<endl;
    }
    }

}