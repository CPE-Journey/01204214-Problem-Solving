#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,A,B,W,remain,node,dist,currentDistance;

vector<vector<int>> graph;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> shortest; // Distance , Node
vector<int> visited;
pair<int,int> selected;

// void printHeap(){
//     for(int i=0;i<N;i++){
//         printf("(%d, %d) ",shortest[i].first,shortest[i].second);
//     }
// }

int Min(int a,int b){
    return a < b ? a : b;
}

int main(){
    cin >> N >> M;
    graph.resize(N,vector<int>(N));

    for(int i=0;i<M;i++){
        cin >> A >> B >> W;
        graph[A-1][B-1] = W;
        graph[B-1][A-1] = W;
    }
    
    for(int i=0;i<N;i++){
        visited.push_back(0);
        shortest.push(make_pair(1001,i));
    }

    remain = N;
    while(remain != 0){
        selected = shortest.top();
        shortest.pop();

        node = selected.second;
        dist = selected.first;

        for(int i=0;i<N;i++){
            currentDistance = graph[node][i];
            if(currentDistance+dist)
        }

    }
    
}