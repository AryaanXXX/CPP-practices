#include<iostream>
using namespace std;
int main(){
    int A[2][3];

    //getting user input for 2D array
    cout<<"Enter elelments for the matrix:"<<endl;
    for(int row=0; row<2; row++){
        for(int col=0; col<3; col++){

            cout<<"A["<<row<<"]["<<col<<"] =";
            cin>>A[row][col];
        }
    }
    //uisng loop for printing
    for(int row=0; row<2; row++){
        for(int col=0; col<3; col++){
            cout<<A[row][col]<<" ";
        }
        cout<<endl;
    }
}