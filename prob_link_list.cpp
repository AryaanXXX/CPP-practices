#include<iostream>
using namespace  std;

struct Node{
    int data;
    Node *next;
};

Node *head=nullptr;  //global head pointer

//traversal
void traversal(Node *ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;

}


//update the Node value
bool updateNodeValue(Node *head,int oldValue,int newValue){
    Node *p=head;
    while(p!=nullptr){
        if(p->data==oldValue){  //Checks whether the current node’s data matches oldValue.
            p->data=newValue;   //f a match is found, the node’s data is updated with newValue.
            return true;
        }
        p=p->next;
    }
    return false;
}



//search for a value in linked list
bool searchValue(Node *head,int value){
    Node *p=head;
    while(p!=nullptr){
        if(p->data==value){
            return true;
        }
        p=p->next;
    }
    return false;
}





int main(){
    struct Node *head=new Node();
    struct Node *second=new Node();
    struct Node *third=new Node(); 
    struct Node *fourth=new Node();
    
    
    //linking nodes
    head->data=4;
    head->next=second;

    second->data=3;
    second->next=third; 

    third->data=8;
    third->next=fourth;

    fourth->data=1;
    fourth->next=nullptr;

    cout<<"Calling the traversal function "<<endl;
    traversal(head);

    cout<<"Updating node value 8 to 10 "<<endl;
    if(updateNodeValue(head,8,10)){
        cout<<"Value updated successfully "<<endl;
    }
    else{
        cout<<"Value not found "<<endl;
    }
    traversal(head);



    cout<<"Searching for value 3 in the linked list "<<endl;
    if(searchValue(head,3)){
        cout<<"Value found in the linked list "<<endl;
    }
    else{
        cout<<"Value not found in the linked list "<<endl;      
    }
    traversal(head);


    return 0;
}

















