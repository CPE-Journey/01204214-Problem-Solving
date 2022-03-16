#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,v1,v2,deq,mid;
vector<vector<int>> edge;

int isBipartie(int l,int r){
    vector<vector<int>> graph;
    vector<int> visited,existed;
    list<int> Queue;
    graph.resize(N);
    visited.resize(N);
    existed.resize(N);

    for(int i=l;i<r;i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
        existed[edge[i][0]] = 1;
        existed[edge[i][1]] = 1;
    }

    for(int i=0;i<N;i++){
        if(!existed[i] || visited[i]) continue;
        Queue.push_back(i);
        visited[i] = 1;
        while(!Queue.empty()){
            deq = Queue.front();
            Queue.pop_front();

            for(int i=0;i<graph[deq].size();i++){
                if(!visited[graph[deq][i]]){
                    Queue.push_back(graph[deq][i]);
                    visited[graph[deq][i]] = 3-visited[deq];
                }
                else{
                    if(visited[deq] == visited[graph[deq][i]]){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int searchGraph(int start,int end){
    mid = start + (end-start)/2;
    if(mid == end || mid == start)
        return mid;
    else if(!isBipartie(0,mid)){
        return searchGraph(start,mid);
    }
    else{
        return searchGraph(mid,end);
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        edge.push_back({v1-1,v2-1});
    }
    cout << searchGraph(0,M+1);
    return 0;
}