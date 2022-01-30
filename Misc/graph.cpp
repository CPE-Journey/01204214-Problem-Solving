#include <iostream>
#include <vector>
using namespace std;

int N,M,v1,v2,count=0;
vector<vector<int>> graph;
vector<int> visit;

void DFS(int start){
    visit[start] = 1;
    for(int i=0;i<graph[start].size();i++){
        if(visit[graph[start][i]]) continue;
        DFS(graph[start][i]);
    }
}

int main(){
    cin >> N >> M;
    graph.resize(N);
    visit.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
        graph[v2-1].push_back(v1-1);
    }

    for(int i=0;i<N;i++){
        if(!visit[i]){
            DFS(i);
            count++;
        }
    }
}