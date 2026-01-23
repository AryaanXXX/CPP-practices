#include<iostream>
using namespace  std;

void display(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


void insertionsort(int arr[], int n){

    for (int i = 0; i < n-1; i++)
    {
        int key=arr[i];
        int j=i-1;
        //loop for each pass
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;   //bcuz the loops stops when j=-1 and it beccomes -1+1=0 so we have to put key at 0th index.

    }


}



int main(){
    int a[]={64, 25, 12, 22, 11};
    int n=sizeof(a)/sizeof(a[0]);

    cout<<"Before sorting the array :"<<endl;
    display(a,n);
    cout<<endl;
    cout<<"After sorting the array :"<<endl;
    insertionsort(a,n);
    display(a,n);

    return 0;
}











//doin linear search
#include<iostream>
using namespace  std;

void display(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
        
    }
    cout<<endl;
}

void linearsearch(int arr[],int n,int target){
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==target)
        {
            cout<<"Found at index "<<i<<endl;
            return;
        }
        
    }
    cout<<"Not found"<<endl;

    

}



int main(){
    int arr[]={10,20,30,40,50};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=30;
    cout<<"The array is :"<<endl;
    display(arr,n);
    linearsearch(arr,n,target);

    return 0;
}


















