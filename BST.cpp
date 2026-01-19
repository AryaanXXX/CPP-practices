#include <iostream>
using namespace std;

/* =========================
   BST NODE DEFINITION
   ========================= */
struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        key = val;
        left = right = parent = NULL;
    }
};

/* =========================
   INORDER TRAVERSAL
   ========================= */
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void BST_Insert(Node*& root, Node* z) {
    Node* y = NULL;     // parent pointer
    Node* x = root;     // current pointer

    // Traverse down until x becomes NULL
    while (x != NULL) {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    // y is parent of z
    z->parent = y;

    // Tree was empty
    if (y == NULL)
        root = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}

/* =========================
   SEARCH FUNCTION
   ========================= */
Node* BST_Search(Node* root, int key) {
    while (root != NULL && root->key != key) {
        if (key < root->key)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

/* =========================
   MINIMUM
   ========================= */
Node* Tree_Minimum(Node* x) {
    while (x->left != NULL)
        x = x->left;
    return x;
}

/* =========================
   MAXIMUM
   ========================= */
Node* Tree_Maximum(Node* x) {
    while (x->right != NULL)
        x = x->right;
    return x;
}

/* =========================
   SUCCESSOR
   ========================= */
Node* Tree_Successor(Node* x) {
    if (x->right != NULL)
        return Tree_Minimum(x->right);

    Node* y = x->parent;
    while (y != NULL && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

/* =========================
   PREDECESSOR
   ========================= */
Node* Tree_Predecessor(Node* x) {
    if (x->left != NULL)
        return Tree_Maximum(x->left);

    Node* y = x->parent;
    while (y != NULL && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

/* =========================
   TRANSPLANT (CORE OF DELETE)
   ========================= */
void Transplant(Node*& root, Node* u, Node* v) {
    // Case 1: u is root
    if (u->parent == NULL)
        root = v;

    // Case 2: u is left child
    else if (u == u->parent->left)
        u->parent->left = v;

    // Case 3: u is right child
    else
        u->parent->right = v;

    // Fix parent pointer of v
    if (v != NULL)
        v->parent = u->parent;
}

/* =========================
   BST DELETE
   ========================= */
void BST_Delete(Node*& root, Node* z) {

    // Case 1: No left child
    if (z->left == NULL)
        Transplant(root, z, z->right);

    // Case 2: No right child
    else if (z->right == NULL)
        Transplant(root, z, z->left);

    // Case 3 & 4: Two children
    else {
        Node* y = Tree_Minimum(z->right);

        // Case 3: successor is not immediate child
        if (y->parent != z) {
            Transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        // Case 4: successor is immediate child
        Transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
    }

    delete z;
}

/* =========================
   MAIN FUNCTION
   ========================= */
int main() {
    Node* root = NULL;

    int values[] = {15, 3, 6, 18, 7, 17, 20, 2, 4, 13, 9, 12};

    for (int v : values)
        BST_Insert(root, new Node(v));

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    Node* z = BST_Search(root, 6);
    if (z != NULL) {
        BST_Delete(root, z);
        cout << "After deleting 6: ";
        inorder(root);
        cout << endl;
    }

    Node* x = BST_Search(root, 13);
    if (x != NULL) {
        Node* s = Tree_Successor(x);
        Node* p = Tree_Predecessor(x);

        if (s) cout << "Successor of 13: " << s->key << endl;
        if (p) cout << "Predecessor of 13: " << p->key << endl;
    }

    return 0;
}










