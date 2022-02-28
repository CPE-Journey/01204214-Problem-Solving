#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,S,T,v1,v2,deq;
vector<vector<int>> graph;
vector<int> visit,level;
list<int> Queue;

int BFS(){
    int current_level = 0;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();
        current_level = level[deq];
        for(int i=0;i<graph[deq].size();i++){
            if(visit[graph[deq][i]]) continue;
            Queue.push_back(graph[deq][i]);
            visit[graph[deq][i]] = 1;
            level[graph[deq][i]] = current_level+1;
        }
    }
}

int main(){
    cin >> N >> M >> S >> T;

    graph.resize(N);
    visit.resize(N);
    level.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
        graph[v2-1].push_back(v1-1);
    }

    for(int i=0;i<S;i++){
        cin >> v1;
        Queue.push_back(v1-1);
        visit[v1-1] = 1;
    }
    BFS();

    for(int i=0;i<T;i++){
        cin >> v1;
        cout << level[v1-1] << "\n";
    }

    return 0;
}