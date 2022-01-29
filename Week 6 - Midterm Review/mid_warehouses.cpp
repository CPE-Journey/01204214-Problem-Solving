#include <iostream>
#include <list>
#include <vector>
using namespace std;

int N,M,K,v1,v2,pathFound;
vector<vector<int>> path;
vector<int> visit;
list<int> Stack;

void DFS(int start,int end){
    visit[start] = 1;
    Stack.push_back(start);
    for(int i=0;i<path[start].size();i++){
        if(path[start][i] == end){
            pathFound = 1;
            return;
        }
        else if(visit[path[start][i]]) continue;
        DFS(path[start][i],end);
    }
}

int findPath(int start,int end){
    pathFound = 0;
    for(int i=0;i<N;i++){
        visit[i] = 0;
    }
    DFS(start,end);
    return pathFound;
}

void printPath(){
    for(int i=0;i<path.size();i++){
        cout << i << ": ";
        for(int j=0;j<path[i].size();j++){
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    cin >> N >> M >> K;
    path.resize(N);
    visit.resize(N);
    
    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        path[v1-1].push_back(v2-1);
        path[v2-1].push_back(v1-1);
    }

    for(int i=0;i<K;i++){
        cin >> v1 >> v2;
        cout << findPath(v1-1,v2-1) << "\n";
        while(!Stack.empty()){
            visit[Stack.back()] = 0;
            Stack.pop_back();
        }
    }
    return 0;
}