#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,v1,v2,deq,team;
vector<vector<int>> graph;
vector<pair<int,int>> edge;
vector<int> visit;
list<int> Queue;

int BipartieBFS(int start,int a,int b){
    Queue.push_back(start);
    visit[start] = 1;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();
        team = visit[deq];
        
        for(int i=0;i<graph[deq].size();i++){
            if(!visit[graph[deq][i]]){
                Queue.push_back(graph[deq][i]);
                visit[graph[deq][i]] = 3-team;
            }
            else{
                if(visit[graph[deq][i]] == team && ((deq != a && i != b) || (deq != b && i != a))){
                    return 0;
                }
            }
        }
    }
    return 1;
}

int isBipartie(int a,int b){
    visit.clear();
    visit.resize(N);
    int pass = 1;
    for(int i=0;i<N;i++){
        if(!pass){
            return 0;
        }
        else if(!visit[i]){
            pass = BipartieBFS(i,a,b);
        }
    }
    return 1;
}

int main(){
    cin >> N >> M;

    graph.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
        graph[v2-1].push_back(v1-1);
        edge.push_back(make_pair(v1-1,v2-1));
    }
    
    for(int i=0;i<M;i++){
        if(isBipartie(edge[i].first,edge[i].second)){
            cout << edge[i].first+1 <<  " " << edge[i].second+1;
            return 0;
        }
    }
}