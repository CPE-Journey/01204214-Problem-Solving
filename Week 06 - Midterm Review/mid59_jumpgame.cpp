#include <iostream>
#include <vector>
using namespace std;

int N,K,input;
bool result = false;
vector<vector<int>> graph,visited;

void printVis(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

void travel(int si,int sj){
    if(visited[si][sj]) return;
    if(si == N-1 && sj == N-1){
        result = true;
    }
    visited[si][sj] = 1;
    // Up
    if(si != 0 && graph[si-1][sj] - graph[si][sj] <= K){
        travel(si-1,sj);
    }

    // Down
    if(si != N-1 && graph[si+1][sj] - graph[si][sj] <= K){
        travel(si+1,sj);
    }

    // Left
    if(sj != 0 && graph[si][sj-1] - graph[si][sj] <= K){
        // printf("(%d %d)\n",graph[si][sj-1],graph[si][sj]);
        travel(si,sj-1);
    }

    // Right
    if(sj != N-1 && graph[si][sj+1] - graph[si][sj] <= K){
        travel(si,sj+1);
    }
}

int main(){
    cin >> N >> K;
    graph.resize(N);
    visited.resize(N,vector<int>(N));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> input;
            graph[i].push_back(input);
        }
    }

    travel(0,0);
    if(result){
        cout << "yes\n";
    }
    else{
        cout << "no\n";
    }
    return 0;
}