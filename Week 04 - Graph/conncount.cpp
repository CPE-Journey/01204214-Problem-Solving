#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<int> visit;

void DFS(int start){
    visit[start] = 1;
    for(int i=0;i<graph[start].size();i++){
        if(!visit[graph[start][i]]){
            DFS(graph[start][i]);
        }
    }
}

int main(){
    int N,M,v1,v2,count = 0;
    cin >> N >> M;

    graph.resize(N);
    visit.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for(int i=0;i<N;i++){
        if(visit[i]) continue;
        DFS(i);
        count++;
    }
    
    cout << count << "\n";
    return 0;
}