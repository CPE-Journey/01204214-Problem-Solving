#include <iostream>
#include <vector>
using namespace std;

int N,M,v1,v2,day=0,reach_limit=0;
vector<vector<int>> graph;
vector<int> visited,head,depth;

int findHead(int h){
    if(head[h] == h){
        return h;
    }
    return findHead(head[h]);
}

void unionHead(int a,int b){
    if(depth[a] > depth[b]){
        head[b] = a;
    }
    else if(depth[b] > depth[a]){
        head[a] = b;
    }
    else{
        head[b] = a;
        depth[a] += 1;
    }
}

void showDepth(){
    for(int i=0;i<=N;i++){
        cout << visited[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<=N;i++){
        cout << head[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<=N;i++){
        cout << depth[i] << " ";
    }
    cout << "\n";
}

int main(){
    cin >> N >> M;

    graph.resize(N+1);
    for(int i=0;i<=N;i++){
        visited.push_back(0);
        head.push_back(i);
        depth.push_back(0);
    }

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        if(!visited[v1] && !visited[v2]){
            visited[v1] = 1;
            visited[v2] = 2;
            unionHead(v1,v2);
            // cout << "1\n";
        }
        else if(visited[v1] && visited[v2]){
            if(visited[v1] == visited[v2] && findHead(v1) == findHead(v2)){
                // cout << "2.1\n";
                reach_limit = 1;
            }
            else{
                // cout << "2.2\n";
                unionHead(v1,v2);
            }
        }
        else if(visited[v1]){
            visited[v2] = 3-visited[v1];
            unionHead(v1,v2);
            // cout << "3\n";
        }
        else{
            visited[v1] = 3-visited[v2];
            unionHead(v1,v2);
            // cout << "4\n";
        }
        // showDepth();
        if(!reach_limit){
            day++;
        }
    }
    cout << day;
}