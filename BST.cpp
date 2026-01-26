#include <iostream>
using namespace std;

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

// Inorder Traversal
void inorder(Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// BST Insert
void bst_insert(Node *&root, Node *z) {
    Node *y = nullptr;   // parent
    Node *x = root;      // current node

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

// BST Search
Node* bst_search(Node *root, char key) {
    while (root != nullptr && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// Minimum
Node* tree_minimum(Node *x) {
    while (x->left != nullptr)
        x = x->left;
    return x;
}

// Maximum
Node* tree_maximum(Node *x) {
    while (x->right != nullptr)
        x = x->right;
    return x;
}

// Successor
Node* tree_successor(Node *x) {
    if (x->right != nullptr)
        return tree_minimum(x->right);

    Node *y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

// Predecessor
Node* tree_predecessor(Node *x) {
    if (x->left != nullptr)
        return tree_maximum(x->left);

    Node *y = x->parent;
    while (y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

// Transplant
void transplant(Node *&root, Node *u, Node *v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;
}



// BST Delete
void bst_delete(Node *&root, Node *z) {
    if (z->left == nullptr)
        transplant(root, z, z->right);
    else if (z->right == nullptr)
        transplant(root, z, z->left);
    else {
        Node *y = tree_minimum(z->right);

        if (y->parent != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

// Main Function
int main() {
    Node *root = nullptr;

    char values[] = {'F', 'B', 'G', 'A', 'D', 'I', 'C', 'E'};
    for (char v : values) {
        bst_insert(root, new Node(v));
    }

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    Node *z = bst_search(root, 'D');
    if (z != nullptr) {
        bst_delete(root, z);
        cout << "After deleting D: ";
        inorder(root);
        cout << endl;
    }

    Node *x = bst_search(root, 'E');
    if (x != nullptr) {
        Node *s = tree_successor(x);
        Node *p = tree_predecessor(x);

        if (s) cout << "Successor of E: " << s->key << endl;
        if (p) cout << "Predecessor of E: " << p->key << endl;
    }

    return 0;
}




