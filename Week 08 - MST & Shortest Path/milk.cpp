#include <iostream>
#include <vector>
using namespace std;

int N,Q,h1,h2,x,y;
char opr;
vector<int> head,level;

int findHead(int n){
    return head[n] == n ? n : findHead(head[n]);
}

void unionHead(int a,int b){
    if(level[a] > level[b]){
        head[b] = a;
    }
    else if(level[a] < level[b]){
        head[a] = b;
    }
    else{
        head[b] = a;
        level[a] += 1;
    }
}

int main(){
    cin >> N >> Q;
    
    for(int i=0;i<N;i++){
        head.push_back(i);
        level.push_back(0);
    }

    for(int i=0;i<Q;i++){
        cin >> opr >> x >> y;
        h1 = findHead(x-1);
        h2 = findHead(y-1);
        if(opr == 'q'){
            if(h1 == h2){
                cout << "yes\n";
            }
            else{
                cout << "no\n";
            }
        }
        else{
            unionHead(h1,h2);
        }
    }
    return 0;
}