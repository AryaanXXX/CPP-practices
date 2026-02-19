#include<iostream>
using namespace  std;

int main(){
    int a[5],found=0;;
    cout<<"Enter an array ";
    for(int i=0; i<5; i++){
        cin>>a[i];
    }
    int item=3;
    for(int i=0; i<5; i++){
        if(a[i]==item){
            found=1;   //i can use something here. 
            break;
        }
    }
   if(found){
    cout<<"Item found "<<endl;

   }else{
    cout<<"File not found"<<endl;
   }
}