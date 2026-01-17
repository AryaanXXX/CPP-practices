// doing bubble sort

#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void bubblesort(int arr[], int n)
{
    int issorted=0;

    for (int i = 0; i < n - 1; i++)   // for num of pases
    { 
        cout<<"working on pass number "<<i+1<<endl;
        issorted=1;  // assuming the array is sorted

        for (int j = 0; j < n - 1 - i; j++)
        { 
            if(arr[j]>arr[j+1]){   // and this loop is for comparison in each pass
                // swapping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                issorted=0; // if we had to swap, then the array was not sorted
            }
        }
        if(issorted){
            return;  
        }
    }
}

int main()
{
    //int a[]={1,2,3,4,5};
    int a[] = {12, 54, 65, 7, 23, 9};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Initial Array: "; // printing the initial array before sorting
    display(a, n);
    bubblesort(a, n);               // print the bubble sort process
    cout << "Final Sorted Array: "; // printing the final sorted array after sorting
    display(a, n);
    cout << endl << endl;

    return 0;
    
}
