#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,v1,v2,w,remaining = 0;
vector<vector<pair<int,int>>> graph; // Connect Edge, Weight
vector<int> shortest,visited;
priority_queue<pair<int,int>> heap; // Shorest, Node

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

    // cout << "\n";
    // for(int i=0;i<N;i++){
    //     cout << i << ": ";
    //     for(int j=0;j<graph[i].size();j++){
    //         printf("%d(%d) ",graph[i][j].first,graph[i][j].second);
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    int s_node,s_dist;
    pair<int,int> select;
    remaining = N;
    while(remaining){
        select = heap.top();
        heap.pop();
        s_node = select.second;
        s_dist = -select.first;


        // printf("Extract %d Min Value %d\n",s_node,s_dist);
        if(visited[s_node]) continue;
        visited[s_node] = 1;
        remaining--;

        for(int j=0;j<graph[s_node].size();j++){
            // cout << "PASS\n";
            if(!visited[graph[s_node][j].first]){
                // cout << "PASS\n";
                // printf("%d still not visited\n",graph[s_node][j].first);
                shortest[graph[s_node][j].first] = Min(shortest[graph[s_node][j].first],s_dist+graph[s_node][j].second);
                // cout << "PASS\n";
                heap.push(make_pair(Max(-shortest[graph[s_node][j].first],-(s_dist+graph[s_node][j].second)),graph[s_node][j].first));
                // cout << "PASS\n";
            }
            // cout << "*******\n";
        }
        // cout << "----------------\n";
    }
                // printShortest();
    cout << shortest[N-1];
}