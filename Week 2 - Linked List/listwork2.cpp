#include <iostream>
#include <list>
using namespace std;

void printList(list<int> l){
    for(auto i=l.begin();i!=l.end();++i){
        cout << *i << "\n";
    }
}

int main(){
    int n,value;
    char opr;
    list<int> list;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> opr >> value;
        if(opr == 'I'){
            list.push_front(value);
        }
        else if(opr == 'A'){
            list.push_back(value);
        }
        else if(list.size() >= value){
            auto order = list.begin();
            advance(order,value-1);
            list.erase(order);
        }
    }

    printList(list);
    return 0;
}