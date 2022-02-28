#include <iostream>
#include <list>
#include <vector>
using namespace std;

int N,r,d,hp;
vector<list<int>> necklace;
vector<int> head;

int getHead(int start){
    if(head[start] == start) return start;
    return getHead(head[start]);
}

int main(){
    cin >> N;
    necklace.resize(N);
    
    for(int i=0;i<N;i++){
        necklace[i].push_back(i);
        head.push_back(i);
    }
    
    for(int i=0;i<N-1;i++){
        cin >> r >> d;
        r--;d--;
        hp = getHead(d);
        for(auto j=necklace[hp].begin();j!=necklace[hp].end();++j){
            if(*j == d+1){
                necklace[hp].splice(j,necklace[r]);
                head[r] = d;
                break;
            }
        }
    }

    for(auto i:necklace[hp]){
        cout << i << " ";
    }
}