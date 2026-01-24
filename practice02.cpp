#include<iostream>
using namespace  std;

//doing the bst code by using char 
struct Node{
    char key;
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
void insert(Node *&root, Node *z){
    Node *y=nullptr;
    Node *x=root;
    while(x!=nullptr){
        y=x;   //parent pointer bcuz x is moving
        if(z->key < x->key){
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    z->parent=y;  // y is parent of z
    if(y==nullptr){
        root=z;
    else if(z->key < y->key){
        y->left=z;
    }
    else{
        y->right=z;
    }
}



//search function
Node *search(Node *root, char key){
    whule(root!=nullptr && root->key!=key){
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
Node *minimum(Node *x){
    while(x->left!=nullptr){
        x=x->left;
    }
    return x;
}


//maximum function
Node *maximum(Node *x){
    if(x->right!=nullptr){
        x=x->right;
    }
    return x;
}



//successor function
Node *successor(Node *x){
    if(x->right!=nullptr){
        return minimum(x->right);
    }
    Node *y=x->parent;
    while(y!=nullptr && x==y->right){
        x=y;
        y=y->parent;
    }
    return y;
}


//predecessor function
Node *predecessor(Node *x){
    if(x->left!=nullptr){
        return maximum(x->left);
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
    //case 1: u is root
    if(u->parent==nullptr){
        root=v;
    }
    //case 2: u is left child
    else if(u==u->parent->left){
        u->parent->left=v;
    }       
    //case 3: u is right child
    else{
        u->parent->right=v;
    }
    if(v!=nullptr){
        v->parent=u->parent;
    }
}



//bst delete function
void bst_delete(Node *&root, Node *z){
    //case 1: no left child         
    if(z->left==nullptr){
        transplant(root, z, z->right);
    }   
    //case 2: no right child
    else if(z->right==nullptr){
        transplant(root, z, z->left);
    }
    //case 3 & 4: two children
    else{
        Node *y=minimum(z->right);
        //case 3: successor is not immediate child
        if(y->parent!=z){
            transplant(root, y, y->right);
            y->right=z->right;
            y->right->parent=y;
        }
        //case 4: successor is immediate child
        transplant(root, z, y);
        y->left=z->left;
        y->left->parent=y;
    }
    delete z;
}





int main(){
    Node *root=nullptr;
    char values[]={'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H'};
    for(char val:values){
        insert(root, new Node(val));
    }

    cout<<"Inorder traversal of the BST: ";
    inorder(root);
    cout<<endl;

    Node *z=search(root, 'D');
    if(z!=nullptr){
        cout<<"Deleting Node with key: "<<z->key<<endl;
        bst_delete(root, z);
        cout<<"Inorder traversal after deletion: ";
        inorder(root);
        cout<<endl;
    }


    Node *x=search(root, 'E');
    if(x!=nullptr{
        Node *s=successor(x);
        Node *p=predecessor(x);

        if(s)  cout<<"Successor of E:"<<s->key<<endl;
        if(p)  cout<<"Predeccesor of E:"<<p->key<<endl;
        

    }


    
    return 0;
}






