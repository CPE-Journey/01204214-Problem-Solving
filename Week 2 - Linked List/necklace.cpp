#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<list<int>> necklace;
vector<int> head;
vector<int> inFront;

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

// int updateHead(int start){
//     if(inFront[start]){
//         return start;
//     }
//     head[start] = updateHead(head[start]);
// }

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

int getHead(int self){
    if(self==head[self]){
        return self;
    }
    int rtn = getHead(head[self]);
    // cout << "RTN: " << rtn << "\nBefore: ";
    // cout << head[self] << " After: ";
    head[self] = rtn;
    // cout << head[self] << "\n";
    return rtn;
}

int main(){
    // head = {0,0,1,2,3};
    // cout << getHead(4);
    // printVector(head);
    int N,inserter,inserted,hp,recent;

    cin >> N;

    necklace.resize(N);

    for(int i=0;i<N;i++){
        necklace[i].push_back(i+1);
        head.push_back(i);
        inFront.push_back(-1);
    }

    for(int i=0;i<N-1;i++){
        cin >> inserter >> inserted;
        inserter--;
        inserted--;
        // printVector(head);
        hp = getHead(inserted);
        for(auto j=necklace[hp].begin();j!=necklace[hp].end();++j){
            if (*j == inserted+1){
                necklace[hp].splice(++j,necklace[inserter]);
                break;
            }
        }
        // inFront[inserter] = inserted;
        // printVector(inFront);
        head[inserter] = head[inserted];
        // updateHead(inserter);
        // printVector(inFront);
        // printVector(head);
        // cout << "\n";
        // updateHead();
        // printList(inFront);
    }

    // printVector(head);
    // updateHead();
    // printVector(inFront);

    for(auto i:necklace[hp]){
        cout << i << " ";
    }
    return 0;

}