#include <iostream>
#include <list>
#include <vector>
using namespace std;

void printList(vector<list<int>> List){
    cout << "----------\n";
    for(int i=0;i<List.size();i++){
        cout << i << ": ";
        for(auto j:List[i]){
            cout << j << " -> ";
        }
        cout << "\n";
    }
}

void printHead(vector<int> head){
    cout << "HEADLIST: ";
    for(int i=0;i<head.size();i++){
        
        cout << head[i] << " ";
    }
    cout << "\n";
}

int getHead(vector<int> v,vector<int> exist,int self){
    if(self==v[self] || !exist[self]){
        return self;
    }
    v[self] = getHead(v,exist,v[self]);
    cout << self << " Are Now " << v[self] << "\n";
    return self;
    // return getHead(v,v[self]);
}

int main(){
    int N,inserter,inserted,hp,recent;
    cin >> N;
    vector<list<int>> necklace(N);
    vector<int> head;
    vector<int> exist;

    for(int i=0;i<N;i++){
        necklace[i].push_back(i+1);
        head.push_back(i);
        exist.push_back(1);
    }

    for(int i=0;i<N-1;i++){
        cin >> inserter >> inserted;
        inserter--;
        inserted--;
        hp = getHead(head,exist,inserted);
        cout << "HEADPOINT: " << hp << "\n";
        for(auto j=necklace[hp].begin();j!=necklace[hp].end();++j){
            if (*j == inserted+1){
                necklace[hp].splice(++j,necklace[inserter]);
                break;
            }
        }
        // cout << "Before" << head[inserter];
        exist[inserter] = 0;
        head[inserter] = head[inserted];
        // cout << " After " << head[inserter] << "\n";
        printList(necklace);
        printHead(head);
    }
    cout << hp;
    for(auto i:necklace[hp]){
        cout << i << " ";
    }
    return 0;

}