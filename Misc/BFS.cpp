#include <iostream>
#include <vector>
#include <list>
using namespace std;

int x;
vector<vector<int>> graph;
vector<int> visit;
list<int> Queue;

void BFS(int start,int end){
    visit[start] = 1;
    Queue.push_back(start);
    while(!Queue.empty()){
        x = Queue.front();
        Queue.pop_front();

        for(int i=0;i<graph[x].size();i++){
            if(visit[graph[x][i]]) continue;
            Queue.push_back(graph[x][i]);
            visit[graph[x][i]] = 1;
        }
    }
}

int main(){
    
}