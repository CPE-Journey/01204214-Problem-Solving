#include <iostream>
#include <vector>
#include <list>
using namespace std;

int node=0,edge=0,v1,v2,deq;
vector<vector<int>> input,graph;
vector<int> degree;
list<int> Queue;

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> node >> edge;
    graph.resize(node);
    degree.resize(node);

    while(true){
        cin >> v1 >> v2;
        if(v1 == 0 && v2 == 0)
            break;
        
        graph[v1-1].push_back(v2-1);
        degree[v2-1] += 1;
    }

    for(int i=0;i<node;i++){
        if(degree[i] == 0){
            Queue.push_back(i);
        }
    }

    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();
        cout << deq+1 << " ";

        for(int i=0;i<graph[deq].size();i++){
            degree[graph[deq][i]] -= 1;
            if(degree[graph[deq][i]] == 0){
                Queue.push_back(graph[deq][i]);
            }
        }
    }
    return 0;
}