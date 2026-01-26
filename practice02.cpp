#include <iostream>
using namespace std;

// BST node using char
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

// inorder traversal
void inorder(Node *root) {
    if (root != nullptr) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// insert function
void insert(Node *&root, Node *z) {
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

    if (y == nullptr) {
        root = z;
    }
    else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
}


// search function
Node *search(Node *root, char key) {
    while (root != nullptr && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}



// minimum
Node *minimum(Node *x) {
    while (x->left != nullptr)
        x = x->left;
    return x;
}


// maximum
Node *maximum(Node *x) {
    while (x->right != nullptr)
        x = x->right;
    return x;
}

// successor
Node *successor(Node *x) {
    // Case 1: Right subtree exists
    if (x->right != nullptr)
        return minimum(x->right);

    // Case 2: No right subtree
    Node *y = x->parent;
    while (y != nullptr && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}


// predecessor
Node *predecessor(Node *x) {
    // Case 1: Left subtree exists
    if (x->left != nullptr)
        return maximum(x->left);

    // Case 2: No left subtree
    Node *y = x->parent;
    while (y != nullptr && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}



// transplant
void transplant(Node *&root, Node *u, Node *v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;  //v must now point to u’s parent
}



// delete
void bst_delete(Node *&root, Node *z) {
    if (z->left == nullptr)
        transplant(root, z, z->right);
    else if (z->right == nullptr)
        transplant(root, z, z->left);
    else {
        Node *y = minimum(z->right);

        if (y->parent != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
}



// main
int main() {
    Node *root = nullptr;
    char values[] = {'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H'};

    for (char val : values) {
        insert(root, new Node(val));
    }

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    Node *z = search(root, 'D');
    if (z != nullptr) {
        cout << "Deleting: " << z->key << endl;
        bst_delete(root, z);
        inorder(root);
        cout << endl;
    }

    Node *x = search(root, 'E');
    if (x != nullptr) {
        Node *s = successor(x);
        Node *p = predecessor(x);

        if (s) cout << "Successor of E: " << s->key << endl;
        if (p) cout << "Predecessor of E: " << p->key << endl;
    }

    return 0;
}




