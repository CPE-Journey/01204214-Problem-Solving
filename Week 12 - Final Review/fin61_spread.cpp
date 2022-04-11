#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> head,depth,speed;

int Ceil(int n,int d){
    int rem = n%d;
    cout << rem << "\n";
    int res = n/d;
    cout << res << "\n";
    if(rem != 0){
        return res+1;
    }
    return res;
}

int findHead(int n){
    if(head[n]==n)
        return n;
    return findHead(head[n]);
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
    cout << "Hello";
    cout << Ceil(5,2);
}