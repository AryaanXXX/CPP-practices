#include <iostream>
#include <queue>
using namespace std;

// Node structure
struct Node {
    char key;
    Node *left;
    Node *right;
    Node *parent;

    Node(char val) {
        key = val;
        left = right = parent = nullptr;
    }
};

// BST Insert
void bst_insert(Node *&root, Node *z) {
    Node *y = nullptr;
    Node *x = root;

    while (x != nullptr) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;

    if (y == nullptr)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

// Inorder Traversal
void inorder(Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// BFS (Level Order Traversal)
void bfs(Node *root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *current = q.front();
        q.pop();

        cout << current->key << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

// Main
int main() {
    Node *root = nullptr;

    char values[] = {'F', 'B', 'G', 'A', 'D', 'I', 'C', 'E'};
    for (char v : values) {
        bst_insert(root, new Node(v));
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(root);
    cout << endl;

    return 0;
}







