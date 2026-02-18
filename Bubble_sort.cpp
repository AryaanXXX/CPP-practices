#include<iostream>
using namespace  std;
int main(){
    int temp,size,a[20];
    cout<<"Enter the size of Array:"<<endl;
    cin>>size;
    cout<<"Enter the arryay element:"<<endl;
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
     
    //using loop for bubble sort.
    for(int i=0; i<size-1; i++){
        for(int j=0; j<(size-i)-1; j++){
            //swap th elements.
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    cout<<"After the bubble sort:"<<endl;
    for(int i=0; i<size; i++){
        cout<<a[i]<<" ";
    }
}
