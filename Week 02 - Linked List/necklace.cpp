#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<list<int>> necklace;
vector<int> head;
vector<int> inFront;

int getHead(int self){
    if(self==head[self]){
        return self;
    }
    int rtn = getHead(head[self]);
    head[self] = rtn;
    return rtn;
}

int main(){
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
        hp = getHead(inserted);
        for(auto j=necklace[hp].begin();j!=necklace[hp].end();++j){
            if (*j == inserted+1){
                necklace[hp].splice(++j,necklace[inserter]);
                break;
            }
        }
        head[inserter] = head[inserted];
    }

    for(auto i:necklace[hp]){
        cout << i << " ";
    }
    return 0;
}