#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,v1,v2,weight,node,dist;
vector<vector<int>> graph;
priority_queue<pair<int,int>> heap;
vector<int> visited,shortest;
pair<int,int> selected_node;

int Max(int a,int b){
    return a > b ? a : b;
}

int Min(int a,int b){
    return a < b ? a : b;
}

int main(){
    cin >> N >> M;

    graph.resize(N,vector<int>(N));
    for(int i=0;i<N;i++){
        visited.push_back(0);
        shortest.push_back(i == 0 ? 0 : 1001);
        heap.push(make_pair(i == 0 ? 0 : -1001,i));
    }

    for(int i=0;i<M;i++){
        cin >> v1 >> v2 >> weight;
        graph[v1-1][v2-1] = weight;
        graph[v2-1][v1-1] = weight;
    }

    for(int i=0;i<N;i++){
        selected_node = heap.top();
        heap.pop();
        node = selected_node.second;
        dist = -selected_node.first;

        if(visited[node]) continue;
        visited[node] = 1;

        for(int j=0;j<graph[node].size();j++){
            if(graph[node][j] != 0 && !visited[j]){
                shortest[j] = Min(shortest[j],dist+graph[node][j]);
                // printf("Shortest: %d -> Path: %d\n",j+1,shortest[j]);
                heap.push(make_pair(Max(-shortest[j],-(dist+graph[node][j])),j));
            }
        }
        // cout << "\n";
    }

    cout << shortest[N-1];
}