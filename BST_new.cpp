#include<iostream>
using namespace  std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node *parent;
    Node(int val){
        key=val;
        left=right=parent=NULL;
    }
};


//inorder function 
void inorder(Node *root){
    if(root!=nullptr){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}


//BST insert function
void bst_insert(Node *&root, Node*z){
    //helper pointers
    Node *y=nullptr;    //parent pointer
    Node *x=root;    //used to move through the tree
    while(x!=nullptr){
        y=x;
        if(z->key < x-> key){
            x=x->left;
        }
        else{
            x=x->right;
        }

    }
    //y is parent of z
    z->parent =y ;

    //tree was empty
    if(y==nullptr)
        root=z;

    else if (z->key < y->key)
        y->left=z;
    else
        y->right=z;

}



//Search Function 
Node *bst_search(Node *root,int key){
    while(root!=nullptr && root->key!=key){
        if(key<root->key){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return root;
}


//minimum function
Node *tree_minimum(Node *x){
    while(x->left!=nullptr){
        x=x->left;
    }
    return x;
}



//maximum function
Node *tree_maximum(Node *x){
    while(x->right!=nullptr){
        x=x->right;
    }
    return x;
}




//successor function
Node *tree_successor(Node *x){
    if(x->right!=nullptr){
        return tree_minimum(x->right);
    }
    Node *y=x->parent;
    while(y!=nullptr && x==y->right){
        x=y;
        y=y->parent;
    }
    return y;
}




//predecessor function
Node *tree_predecessor(Node *x){
    if(x->left!=nullptr){
        return tree_maximum(x->left);
    }
    Node *y=x->parent;
    while(y!=nullptr && x==y->left){
        x=y;
        y=y->parent;
    }
    return y;
}



//transplant function
void transplant(Node *&root, Node *u, Node *v){
    if(u->parent==nullptr){
        root=v;
    }
    else if(u==u->parent->left){
        u->parent->left=v;
    }
    else{
        u->parent->right=v;
    }
    if(v!=nullptr){
        v->parent=u->parent;
    }
}




//delete function
void bst_delete(Node *&root, Node *z){
    //no left child
    if(z->left==nullptr){
        transplant(root,z,z->right);
    }
    //no right child
    else if(z->right==nullptr){
        transplant(root,z,z->left);
    }


    //two children
    else{
        Node *y=tree_minimum(z->right);

        //successor is not immediate child
        if(y->parent!=z){
            transplant(root,y,y->parent);
            y->right=z->right;
            y->right->parent=y;



        }
        //successor is immediate child
        transplant(root,z,y);
        y->left=z->left;
        y->left->parent=y;

         
    }
}



int main(){

    Node *root=nullptr;
    int values[]={15,3,6,18,7,17,20,2,4,13,9,12};
    for(int v: values){
        bst_insert(root,new Node(v));
    }

    cout<<"Inorder Traversal: ";
    inorder (root);
    cout<<endl;

    Node *z=bst_search(root,6);
    if(z!=nullptr){
        bst_delete(root,z);
        cout<<"After deleting 6: ";
        inorder(root);
        cout<<endl;
    }

    Node *x=bst_search(root,13);
    if(x!=nullptr){
        Node *s=tree_successor(x);
        Node *p=tree_predecessor(x);

        if(s)  cout<<"Successor of 13: "<<s->key<<endl;
        if(p)  cout<<"Predecessor of 13: "<<p->key<<endl;
    }


    
    return 0;
}

























