#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,A,B,W,remain,node,currentDistance,dist;

vector<vector<int>> graph;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap; // Distance , Node
vector<int> visited,shortest;
pair<int,int> selected;

int Min(int a,int b){
    return a < b ? a : b;
}

int main(){
    cin >> N >> M;
    graph.resize(N,vector<int>(N));
    // visited.resize(N);
    // dist.resize(N);

    for(int i=0;i<M;i++){
        cin >> A >> B >> W;
        graph[A-1][B-1] = W;
        graph[B-1][A-1] = W;
    }
    
    for(int i=0;i<N;i++){
        visited.push_back(0);
        shortest.push_back(i==0 ? 0 :1001);
        heap.push(make_pair(i==0 ? 0 :1001,i));
    }
    // shortest[0] = 0;

    remain = N-1;
    for(int a=0;a<N;a++){
        selected = heap.top();
        heap.pop();

        node = selected.second;
        dist = selected.first;

        // cout << node << " " << dist << "\n";
        
        visited[node] = 1;
        remain--;
        for(int i=0;i<graph[node].size();i++){
            if(graph[node][i] && !visited[i] && node != i){
                // cout << "New!\n";
                shortest[i] = Min(shortest[i],shortest[node]+graph[node][i]);
                heap.push(make_pair(Min(dist,shortest[node]+graph[node][i]),i));
            }
            for(int i=0;i<N;i++){
                // cout << shortest[i] << " ";
            }
            // cout << "\n\n";
        }
    }
        cout << shortest[N-1] << "\n";
    
    // while(!heap.empty()){
    //     selected = heap.top();
    //     heap.pop();
    //     node = selected.second;
    //     dist = selected.first;
    //     cout << node << " " << dist << "\n";
    // }
    
}