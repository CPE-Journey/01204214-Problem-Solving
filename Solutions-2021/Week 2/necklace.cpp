#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *next;
}List;

List *createNode(int value){
    List *list = new List;
    list->data = value;
    list->next = NULL;
    return list;
}

int main(){
    int n = 5;
    List** llist;
    llist = new List*[n];

    for(int i=0;i<5;i++){
        *(llist+i) = NULL;
    }

    cout << "Nice";
}