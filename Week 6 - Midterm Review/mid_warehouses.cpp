#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,K,v1,v2,pathFound,deq;
vector<vector<int>> path;
vector<int> visit;
list<int> Queue;

int BFS(int start,int end){
    Queue.push_back(start);
    visit[start] = 1;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();
        for(int i=0;i<path[deq].size();i++){
            if(path[deq][i] == end){
                return 1;
            }
            else if(visit[path[deq][i]]) continue;
            visit[path[deq][i]] = 1;
            Queue.push_back(path[deq][i]);
        }
    }
    return 0;
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
        cout << BFS(v1-1,v2-1) << "\n";
    }
    return 0;
}