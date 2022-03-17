#include <iostream>
#include <vector>
#include <list>
using namespace std;

typedef struct{
    int node,color;
}Edge;

int N,M,S,T,v1,v2,c,deq,current_node,current_color,result;
vector<vector<Edge>> graph;

int BFS(int selected_color){
    list<int> Queue;
    vector<int> visited(N);

    Queue.push_back(S);
    visited[S] = 1;
    while(!Queue.empty()){
        deq = Queue.front();
        Queue.pop_front();
        
        if(deq == T){
            return visited[deq]-1;
        }

        for(int i=0;i<graph[deq].size();i++){
            current_node = graph[deq][i].node;
            current_color = graph[deq][i].color;
            // printf("DQ: %d Node: %d Color: %d [!%d && (%d == 0 || %d == %d)]\n",deq,current_node,current_color,visited[current_node],current_color,current_color,selected_color);
            if(!visited[current_node] && (current_color == 0 || current_color == selected_color)){
                Queue.push_back(current_node);
                visited[current_node] = visited[deq]+1;
            }
        }
    }
    return 99999;
}

int Min(int a,int b){
    return a < b ? a : b;
}

int MinOf3(int a,int b,int c){
    return Min(Min(a,b),c);
}

int main(){
    cin >> N >> M >> S >> T;
    S--;T--;
    graph.resize(N);

    for(int i=0;i<M;i++){
        cin >> v1 >> v2 >> c;
        graph[v1-1].push_back({v2-1,c});
        graph[v2-1].push_back({v1-1,c});
    }

    result = MinOf3(BFS(0),BFS(1),BFS(2));

    if(result == 99999)
        cout << "-1\n";
    else
        cout << result << "\n";
}