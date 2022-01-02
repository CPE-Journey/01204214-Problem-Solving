#include <iostream>
#include <vector>
using namespace std;
vector<int> visit;

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void DFS(vector<vector<int>> graph,int start){
    if(visit[start]) return;
    visit[start] = 1;
    for(int i=0;i<graph[start].size();i++){
        DFS(graph,graph[start][i]);
    }
}

int main(){
    int N,M,v1,v2,count = 0;
    cin >> N >> M;

    vector<vector<int>> graph(N);

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
        DFS(graph,i);
        count++;
    }
    
    cout << count << "\n";
    return 0;
}