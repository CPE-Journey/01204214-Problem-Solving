#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,M,v1,v2,weight,pathLength=0,h1,h2;
vector<pair<int,pair<int,int>>> tree;
vector<int> head,depth;

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

void show(){
    for(int i=0;i<N;i++){
        cout << head[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<N;i++){
        cout << depth[i] << " ";
    }
    cout << "\n\n";
}

int main(){
    cin >> N >> M;

    for(int i=0;i<M;i++){
        cin >> v1 >> v2 >> weight;
        tree.push_back(make_pair(weight,make_pair(v1-1,v2-1)));
    }

    sort(tree.begin(),tree.end());

    for(int i=0;i<N;i++){
        head.push_back(i);
        depth.push_back(0);
    }

    for(int i=0;i<M;i++){
        h1 = findHead(tree[i].second.first);
        h2 = findHead(tree[i].second.second);

        if(h1 != h2){
            pathLength += tree[i].first;
            unionHead(h1,h2);
        }
    }

    cout << pathLength;
}