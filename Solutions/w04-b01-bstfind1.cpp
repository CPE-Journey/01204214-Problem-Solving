#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}BSTree;

BSTree *createNode(int value){
    BSTree *t = new BSTree;
    t->data = value;
    t->left = NULL;
    t->right = NULL;
    return t;
}

BSTree *insert(BSTree *t,int value){
    if(t==NULL){
        return createNode(value);
    }
    else if(t->data > value){
        t->left = insert(t->left,value);
    }
    else{
        t->right = insert(t->right,value);
    }
}

int main(){
    BSTree *t = createNode(5);
    t = insert(t,3);
    t = insert(t,10);
    cout << t->left->data << "\n";
    // cout << t->left << "\n";
    // cout << t->right << "\n";
}