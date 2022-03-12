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
    while(true){
        cin >> node >> edge;
        if(!node && !edge){
            break;
        }
        graph.clear();
        degree.clear();
        graph.resize(node);
        degree.resize(node);
        for(int i=0;i<edge;i++){
            cin >> v1 >> v2;
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
        cout << "\n";
    }

    
    return 0;
}