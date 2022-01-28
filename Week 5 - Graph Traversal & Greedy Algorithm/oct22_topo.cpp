#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,v1,v2,deq;
vector<vector<int>> graph;
vector<int> visit;
vector<int> degree;
list<int> queue;

int BFS(int start){
    queue.push_back(start);
    visit[start] = 0;
    while(!queue.empty()){
        deq = queue.front();
        queue.pop_front();
        for(int i=0;i<graph[deq].size();i++){
            if(visit[graph[deq][i]]) return 0;
            queue.push_back(graph[deq][i]);
            visit[graph[deq][i]] = 1;
        }
    }
    return 1;
}

int main(){
    cin >> N >> M;
    graph.resize(N);
    visit.resize(N);
    degree.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
        degree[v2-1] += 1;
    }

    cout << BFS(0);
}