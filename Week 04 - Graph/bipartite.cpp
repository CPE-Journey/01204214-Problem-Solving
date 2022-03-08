#include <iostream>
#include <vector>
#include <list>
using namespace std;

string bipartie(){
    int N,M,v1,v2,deq;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<int> visited(N);
    list<int> Queue;

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        v1--;v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    Queue.push_back(0);
    visited[0] = 1;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();

        for(int i=0;i<graph[deq].size();i++){
            if(!visited[graph[deq][i]]){
                Queue.push_back(graph[deq][i]);
                visited[graph[deq][i]] = 3-visited[deq];
            }
            else{
                if(visited[deq] == visited[graph[deq][i]]){
                    return "no\n";
                }
            }
        }
    }
    return "yes\n";
}

int main(){
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cout << bipartie();
    }
    return 0;
}