#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,L,v1,v2,w,current_distance,new_distance,current_node,minCost=0;
vector<int> shortest,population;
vector<vector<pair<int,int>>> graph; // Connect Edge, Weight
priority_queue<pair<int,int>> heap;  // Shorest, Node

int Min(int a,int b){
    return a > b ? b : a;
}

int main(){
    cin >> N >> M >> L;
    graph.resize(N);
    shortest.push_back(0);
    heap.push(make_pair(0,0));

    for(int i=1;i<N;i++){
        shortest.push_back(999999);
        heap.push(make_pair(-999999,i));
    }

    for(int i=0;i<N;i++){
        cin >> w;
        population.push_back(w);
    }

    for(int i=0;i<M;i++){
        cin >> v1 >> v2 >> w;
        graph[v1-1].push_back(make_pair(v2-1,w));
        graph[v2-1].push_back(make_pair(v1-1,w));
    }

    int s_node,s_dist;
    pair<int,int> select;
    while(!heap.empty()){
        select = heap.top();
        heap.pop();
        s_node = select.second;
        s_dist = -select.first;

        for(int j=0;j<graph[s_node].size();j++){
            
            current_node = graph[s_node][j].first;
            current_distance = shortest[current_node];
            new_distance = s_dist+graph[s_node][j].second;

            if(new_distance < current_distance){
                shortest[current_node] = new_distance;
                heap.push(make_pair(-new_distance,current_node));
            }
        }
    }
    for(int i=1;i<N;i++){
        minCost += shortest[i]*Min(L,population[i]);
    }
    cout << minCost << "\n";
    return 0;
}