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
        shortest.push_back(0);
        heap.push(make_pair(1001,i));
    }

    remain = N;
    while(remain != 0){
        selected = heap.top();
        heap.pop();

        node = selected.second;
        dist = selected.first;
        
        visited[node] = 1;
        for(int i=0;i<graph[node].size();i++){
            if(!visited[graph[node][i]]){
                visited[graph[node][i]] = 1;
                // push อันใหม่เข้าไปเล้ยยยย
            }
        }

        remain--;

        cout << node << " " << dist << "\n";
    }
    
}