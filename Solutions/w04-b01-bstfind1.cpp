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

int main(){

}