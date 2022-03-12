#include <iostream>
#include <vector>
#include <list>
using namespace std;

long long int N,M,v1,v2,deq,mid;
vector<vector<long long int>> edge;

long long int isBipartie(long long int l,long long int r){
    vector<vector<long long int>> graph;
    vector<long long int> visited;
    list<long long int> Queue;
    graph.resize(N);
    visited.resize(N);

    for(long long int i=l;i<r;i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
    }

    Queue.push_back(edge[l][0]);
    visited[edge[l][0]] = 1;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();

        for(long long int i=0;i<graph[deq].size();i++){
            if(!visited[graph[deq][i]]){
                Queue.push_back(graph[deq][i]);
                visited[graph[deq][i]] = 3-visited[deq];
            }
            else{
                if(visited[deq] == visited[graph[deq][i]]){
                    return 0;
                }
            }
        }
    }
    return 1;
}

long long int searchGraph(long long int start,long long int end){
    mid = start + (end-start)/2;
    if(mid == end || mid == start)
        return mid;
    else if(!isBipartie(0,mid)){
        // prlong long intf("A (%d %d)\n",start,mid);
        return searchGraph(start,mid);
    }
    else{
        // prlong long intf("B (%d %d)\n",mid,end);
        return searchGraph(mid,end);
    }
}

int main(){
    cin >> N >> M;
    for(long long int i=0;i<M;i++){
        cin >> v1 >> v2;
        edge.push_back({v1-1,v2-1});
    }

    // for(long long int i=15850;i<15850=;i++){
    //     prlong long intf("%d %d\n",i,isBipartie(0,i));
    // }

    cout << searchGraph(0,M+1);
}