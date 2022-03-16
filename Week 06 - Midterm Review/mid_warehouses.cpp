#include <iostream>
#include <list>
#include <vector>
using namespace std;

int N,M,K,v1,v2,h1,h2;
vector<int> head,depth;

int findHead(int n){
    return head[n] == n ? n : findHead(head[n]);
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
    cin >> N >> M >> K;

    for(int i=0;i<N;i++){
        head.push_back(i);
        depth.push_back(0);
    }
    
    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        h1 = findHead(v1-1);
        // printf("PASS\n");
        h2 = findHead(v2-1);
        // printf("(%d %d)\n",h1,h2);
        if(h1 != h2){
            unionHead(h1,h2);
        }
    }

    for(int i=0;i<K;i++){
        cin >> v1 >> v2;
        h1 = findHead(v1-1);
        h2 = findHead(v2-1);
        if(h1 == h2){
            cout << "1\n";
        }
        else{
            cout << "0\n";
        }
    }
    return 0;
}