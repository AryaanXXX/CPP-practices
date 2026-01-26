//doing all kind of deletion in linked list
#include<iostream>
using namespace  std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr; // global head pointer


//traversal
void traversal(Node *ptr){
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;

}



//deletion at the beginning
Node* deleteAtBeginning(Node *head){
    Node *ptr=head;
    head=head->next;
    delete ptr;
    return head;
}



//deletion at index
Node *deleteAtIndex(Node *head,int index){
    Node *p=head;
    Node *q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    p->next=q->next;
    delete q;
    return head;

}



//deletion at the end
Node *deleteAtEnd(Node *head){
    Node *p=head;
    Node *q=head->next; 
    while(q->next!=nullptr){
        p=p->next;
        q=q->next;

    }
    p->next=nullptr;
    delete q;
    return head;

}



//deletion with a given value
Node *deleteWithValue(Node *head,int value){
    Node *p=head;
    Node *q=head->next;
    while(q->data!=value && q->next!=nullptr){
        p=p->next;
        q=q->next;

    }
    if(q->data==value){
        p->next=q->next;
        delete q;
    }
    return head;

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
    
    cout<<"Linked list before deletion "<<endl;
    traversal(head);

    // cout<<"Deletion Node at the begining "<<endl;
    // head=deleteAtBeginning(head);
    // traversal(head);

    // cout<<"Deletion Node at index 2 "<<endl;
    // head=deleteAtIndex(head,2); 
    // traversal(head);

    // cout<<"Deletion Node at the end "<<endl;
    // head=deleteAtEnd(head); 
    // traversal(head);

    cout<<"Deletion Node with value  "<<endl;
    head=deleteWithValue(head,8); 
    traversal(head);

    return 0;
}














