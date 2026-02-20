#include <iostream>
//#include <stdlib.h> //for using malloc.  //these used in but not in c++.
using namespace std;
struct Node
{
    int data;
    Node *next;
};
void linkedlistTraversal(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    // creating head node.
    struct Node *head;
    struct Node *scound;
    struct Node *third;
    struct Node *fourth;

    // Allocate memory nodes in the linkde list in heap.
    // head=(struct Node *)malloc(sizeof(struct Node));
    // scound=(struct Node *)malloc(sizeof(struct Node));
    // third=(struct Node *)malloc(sizeof(struct Node));
    // fourth=(struct Node *)malloc(sizeof(struct Node));

    // Allocate memory nodes in the linkde list in heap.
    head = new Node();
    scound = new Node();
    third = new Node();
    fourth = new Node();

    // link first and scound node.
    head->data = 7;
    head->next = scound;

    // link scound and third node.
    scound->data = 11;
    scound->next = third; // scound will allocate the memory location of third.

    // link third and fourth node.
    third->data = 41;
    third->next = fourth;

    // terminate the lsit at the fourth node.
    fourth->data = 66;
    fourth->next = NULL;

    // called linkedlistTraversal
    linkedlistTraversal(head);
    return 0;
}