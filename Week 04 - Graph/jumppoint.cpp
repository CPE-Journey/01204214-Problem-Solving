#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,R,x,y,deq;

vector<vector<int>> graph;
vector<vector<int>> node;

vector<int> visit;
list<int> queue;

int distance(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int shortestPath(){
    int count=0,endpoint = graph.size()-1;

    queue.push_back(0);
    visit[0] = 1;
    while(!queue.empty()){
        deq = queue.front();
        queue.pop_front();

        for(int i=0;i<graph[deq].size();i++){
            if(graph[deq][i] == endpoint) return visit[deq];
            if(visit[graph[deq][i]]) continue;
            queue.push_back(graph[deq][i]);
            visit[graph[deq][i]] = visit[deq]+1;
        }
    }
    return -1;
}

int main(){
    cin >> N >> R;
    graph.resize(N+2);
    visit.resize(N+2);
    
    node.push_back({0,0});
    for(int i=0;i<N;i++){
        cin >> x >> y;
        node.push_back({x,y});
    }
    node.push_back({100,100});

    for(int i=0;i<N+2;i++){
        for(int j=i+1;j<N+2;j++){
            if(i==j) continue;
            if(distance(node[i][0],node[i][1],node[j][0],node[j][1]) <= R*R){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    cout << shortestPath();
    return 0;
}