#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,S,T,v1,v2,c,deq,c_level=0;
int passRed = 0,passBlack = 0;
vector<vector<int>> graph;
vector<int> visit,level;
list<int> Queue;

void BFS(int start,int end){
    passRed = 0;
    passBlack = 0;
    visit[start] = 1;
    Queue.push_back(start);
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();

        for(int i=0;i<graph[deq].size();i++){
            if(visit[graph[deq][i]]) continue;
            Queue.push_back(graph[deq][i]);
            visit[graph[deq][i]] = 1;
            level[graph[deq][i]] = c_level+1;
        }
        c_level++;
    }
}

int main(){
    cin >> N >> M >> S >> T;

    graph.resize(N,vector<int>(N));
    visit.resize(N);
    level.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2 >> c;
        graph[v1-1][v2-1] = c+1;
        graph[v2-1][v1-1] = c+1;

        //  0 - Can't reach
        //  1 - No Color
        //  2 - Red Bridge
        //  3 - Black Bridge
    }
}