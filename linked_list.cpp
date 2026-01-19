//Doing all the linked list operations like insertion, deletion, traversal, searching etc in Singly Linked List
#include<iostream>
using namespace  std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr; // global head pointer You don't need to pass the head pointer to every function you write. but poor in larger programs

//traversal
void traversal(Node *ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;

}

//Insertion at the beginning
void insertAtBeginining(Node *&head,int data){
    Node *ptr=new Node();
    ptr->next=head;
    ptr->data=data;
    head=ptr;
    
}


//insertion at index
void insertAtIndex(Node *head,int data, int index){
    Node *ptr=new Node();
    Node *p=head;
    int i=0;
    while(i!=index-1){    //this loop will take us to the node after which we have to insert the new node before given index number.
        p=p->next;
        i++;    
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;

}



//insertion at the end
void insertAtEnd(Node *&head, int data){
    Node *ptr=new Node();
    Node *p=head;
    while(p->next!=nullptr){
        p=p->next;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=nullptr;

}


//inset after a node
void insertAfterNode(Node *head,Node *prevNode,int data){
    Node *ptr=new Node();
    ptr->data=data;

    ptr->next=prevNode->next;
    prevNode->next=ptr;


}

int main(){
   // Node *head = nullptr; // local head pointer
    struct Node *head=new Node();
    struct Node *second=new Node();
    struct Node *third=new Node(); 
    struct Node *fourth=new Node();
    
    
    //linking nodes
    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third; 

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=nullptr;
    
    cout<<"Linked list before insertion "<<endl;
    traversal(head);

    // cout<<"Inserting 5 at the beginning "<<endl;
    // insertAtBeginining(head,5);
    // traversal(head);

    // cout<<"Inserting 25 at index 2 "<<endl;
    // insertAtIndex(head,25,2);
    // traversal(head);

    cout<<"Inserting 15 after second node "<<endl;
    insertAfterNode(head,second,15);
    traversal(head);

    // cout<<"Inserting 50 at the end "<<endl;
    // insertAtEnd(head,50);
    // traversal(head);

    return 0;
}














