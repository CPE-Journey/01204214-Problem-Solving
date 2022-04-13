// #include <iostream>
// #include <vector>
// #include <list>
// using namespace std;

// int N,M,v1,v2,deq,team;
// vector<vector<int>> graph;
// vector<pair<int,int>> edge;
// vector<int> visit;
// list<int> Queue;

// int BipartieBFS(int start,int a,int b){
//     Queue.clear();
//     Queue.push_back(start);
//     visit[start] = 1;
//     while(!Queue.empty()){
//         deq = Queue.front();
//         Queue.pop_front();
//         team = visit[deq];
        
//         for(int i=0;i<graph[deq].size();i++){
//             if(!visit[graph[deq][i]]){
//                 Queue.push_back(graph[deq][i]);
//                 visit[graph[deq][i]] = 3-team;
//             }
//             else{
//                 if(visit[graph[deq][i]] == team && ((deq != a && i != b) || (deq != b && i != a))){
//                     return 0;
//                 }
//             }
//         }
//     }
//     return 1;
// }

// int isBipartie(int a,int b){
//     visit.clear();
//     visit.resize(N);
//     int pass = 1;
//     for(int i=0;i<N;i++){
//         if(!pass){
//             return 0;
//         }
//         else if(!visit[i]){
//             pass = BipartieBFS(i,a,b);
//         }
//     }
//     return 1;
// }

// int main(){
//     cin >> N >> M;

//     graph.resize(N);

//     for(int i=0;i<M;i++){
//         cin >> v1 >> v2;
//         graph[v1-1].push_back(v2-1);
//         graph[v2-1].push_back(v1-1);
//         edge.push_back(make_pair(v1-1,v2-1));
//     }
    
//     for(int i=0;i<M;i++){
//         cout << isBipartie(edge[i].first,edge[i].second) << "\n";
//     }
// }

#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,M,v1,v2,deq,mid,result;
vector<vector<int>> edge;

int isBipartie(int l,int r){
    vector<vector<int>> graph;
    vector<int> visited,existed;
    list<int> Queue;
    graph.resize(N);
    visited.resize(N);
    existed.resize(N);

    for(int i=l;i<r;i++){
        graph[edge[i][0]].push_back(edge[i][1]);
        graph[edge[i][1]].push_back(edge[i][0]);
        existed[edge[i][0]] = 1;
        existed[edge[i][1]] = 1;
    }

    for(int i=0;i<N;i++){
        if(!existed[i] || visited[i]) continue;
        Queue.push_back(i);
        visited[i] = 1;
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
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int searchGraph(int start,int end){
    mid = start + (end-start)/2;
    if(mid == end || mid == start)
        return mid;
    else if(!isBipartie(0,mid)){
        return searchGraph(start,mid);
    }
    else{
        return searchGraph(mid,end);
    }
}

int main(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        edge.push_back({v1-1,v2-1});
    }
    result = searchGraph(0,M+1);
    printf("%d %d\n",edge[result-1][0]+1,edge[result-1][1]+1);
    return 0;
}