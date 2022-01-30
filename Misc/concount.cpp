#include <iostream>
#include <vector>
using namespace std;

int N,M,v1,v2,count = 0;
vector<vector<int>> graph; // {{} {2} {1} {}} 
vector<int> visit; // 0 = Not Visit | 1 = Visited

void DFS(int start){
    visit[start] = 1;
    for(int i=0;i<graph[start].size();i++){
        if(visit[ graph[start][i] ])
            continue;
        DFS(graph[start][i]);
    }
}

int main(){
    cin >> N >> M;
    graph.resize(N);
    visit.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1-1].push_back(v2-1); // Append <-- List Python
        graph[v2-1].push_back(v1-1);
    }

    for(int i=0;i<N;i++){ // O(N) + O(N+M)
        if(!visit[i]){
            DFS(i);
            count++;
        }
    }

    cout << count << "\n";
    return 0;

}