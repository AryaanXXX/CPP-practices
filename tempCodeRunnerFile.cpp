 // insertAtIndex(head,25,2);
    // traversal(head);
#include<iostream>
using namespace  std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};



void insertAtIndex(Node*& head, int data, int index) {
    if (index < 0) return;

    Node* newNode = new Node(data);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < index - 1 && current != nullptr; i++) {
        current = current->next;
    }

    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    } else {
        delete newNode;
    }
}

void traversal(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert elements at different positions
    insertAtIndex(head, 10, 0);
    insertAtIndex(head, 20, 1);
    insertAtIndex(head, 30, 2);
    insertAtIndex(head, 25, 2);
    traversal(head);

    return 0;
}