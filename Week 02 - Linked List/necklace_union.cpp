#include <iostream>
#include <list>
#include <vector>
using namespace std;

vector<list<int>> necklace;
vector<int> head,depth;
vector<int> inFront;

int getHead(int self){
    return head[self] == self ? self : getHead(head[self]);
}

void unionHead(int a,int b){
    if(depth[a] > depth[b]){
        head[b] = a;
    }
    else if(depth[a] < depth[b]){
        head[a] = b;
    }
    else{
        head[b] = a;
        depth[a] += 1;
    }
}

int main(){
    int N,inserter,inserted,hp,recent,hi;

    cin >> N;

    necklace.resize(N);

    for(int i=0;i<N;i++){
        necklace[i].push_back(i+1);
        head.push_back(i);
        inFront.push_back(0);
    }

    for(int i=0;i<N-1;i++){
        cin >> inserter >> inserted;
        inserter--;
        inserted--;

        hi = getHead(inserter);
        hp = getHead(inserted);
        cout << "Hello\n";
        for(auto j=necklace[hp].begin();j!=necklace[hp].end();++j){
            if (*j == inserted+1){
                necklace[hp].splice(++j,necklace[inserter]);
                break;
            }
        }
        unionHead(hi,hp);
        cout << "Hello\n";
    }

    for(auto i:necklace[hp]){
        cout << i << " ";
    }
    return 0;

}