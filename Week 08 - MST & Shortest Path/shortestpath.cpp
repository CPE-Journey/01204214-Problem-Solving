#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,v1,v2,w,remaining = 0,current_distance,new_distance,current_node;
vector<int> shortest,visited;
vector<vector<pair<int,int>>> graph; // Connect Edge, Weight
priority_queue<pair<int,int>> heap;  // Shorest, Node

int Max(int a,int b){
    return a > b ? a : b;
}

int Min(int a,int b){
    return a > b ? b : a;
}

void printShortest(){
    for(int i=0;i<N;i++){
        cout << shortest[i] << " ";
    }
    cout << "\n";
}

int main(){
    cin >> N >> M;
    graph.resize(N);
    visited.resize(N);
    shortest.push_back(0);
    heap.push(make_pair(0,0));

    for(int i=1;i<N;i++){
        shortest.push_back(1001);
        heap.push(make_pair(-1001,i));
    }

    for(int i=0;i<M;i++){
        cin >> v1 >> v2 >> w;
        graph[v1-1].push_back(make_pair(v2-1,w));
        graph[v2-1].push_back(make_pair(v1-1,w));
    }

    int s_node,s_dist;
    pair<int,int> select;
    remaining = N;
    while(remaining){
        select = heap.top();
        heap.pop();
        s_node = select.second;
        s_dist = -select.first;

        if(visited[s_node]) continue;
        visited[s_node] = 1;
        remaining--;

        for(int j=0;j<graph[s_node].size();j++){
            
            current_node = graph[s_node][j].first;
            current_distance = shortest[current_node];
            new_distance = s_dist+graph[s_node][j].second;

            if(!visited[current_node]){
                shortest[current_node] = Min(current_distance,new_distance);
                heap.push(make_pair(Max(-current_distance,-new_distance),current_node));
            }
        }
    }
    cout << shortest[N-1];
}