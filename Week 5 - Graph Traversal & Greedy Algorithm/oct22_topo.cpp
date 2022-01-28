#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,v1,v2,deq;
vector<vector<int>> graph;
vector<int> visit;
vector<int> degree;
list<int> queue;

int main(){
    cin >> N >> M;
    graph.resize(N);
    visit.resize(N);
    degree.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1-1].push_back(v2-1);
        degree[v2-1] += 1;
    }

    for(int i=0;i<degree.size();i++){
        if(degree[i] == 0){
            queue.push_back(i);
        }
    }

    if(queue.empty()){
        cout << "no\n";
        return 0;
    }

    while(!queue.empty()){
        deq = queue.front();
        queue.pop_front();
        cout << deq+1 << "\n";
        for(int i=0;i<graph[deq].size();i++){
            degree[graph[deq][i]] -= 1;
            if(degree[graph[deq][i]] == 0){
                queue.push_back(graph[deq][i]);
            }
        }
    }
    return 0;
}