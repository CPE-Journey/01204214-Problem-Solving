#include <iostream>
#include <vector>
#include <list>
using namespace std;

int R,C,di,dj,A,B,X,Y,min_count=999999;
char input;
vector<vector<char>> graph;
vector<pair<int,int>> dirt;

void printVector(vector<vector<int>> v){
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            printf("%d ",v[i][j]);
        }
        cout << "\n";
    }
    cout << "\n";
}

int Min(int a,int b){
    return a > b ? b : a;
}

int BFSTravel(){
    vector<vector<int>> visited,level;
    list<pair<int,int>> Queue;
    visited.resize(R,vector<int>(C));
    level.resize(R,vector<int>(C));

    Queue.push_back(make_pair(A,B));
    visited[A][B] = 1;
    while(!Queue.empty()){
        // cout << "Work\n";
        di = Queue.front().first;
        dj = Queue.front().second;
        Queue.pop_front();

        if(graph[di][dj] == '#' || graph[di][dj] == '*') continue;
        else if(di == X && dj == Y){
            return level[di][dj];
        }

        if(di != 0 && !visited[di-1][dj] && graph[di-1][dj] != '-' && graph[di][dj] != '-'){
            Queue.push_back(make_pair(di-1,dj));
            visited[di-1][dj] = 1;
            level[di-1][dj] = level[di][dj] + 1;
        }
        if(di != R-1 && !visited[di+1][dj] && graph[di+1][dj] != '-' && graph[di][dj] != '-'){
            Queue.push_back(make_pair(di+1,dj));
            visited[di+1][dj] = 1;
            level[di+1][dj] = level[di][dj] + 1;
        }
        if(dj != 0 && !visited[di][dj-1] && graph[di][dj-1] != '|' && graph[di][dj] != '|'){
            Queue.push_back(make_pair(di,dj-1));
            visited[di][dj-1] = 1;
            level[di][dj-1] = level[di][dj] + 1;
        }
        if(dj != C-1 && !visited[di][dj+1] && graph[di][dj+1] != '|' && graph[di][dj] != '|'){
            Queue.push_back(make_pair(di,dj+1));
            visited[di][dj+1] = 1;
            level[di][dj+1] = level[di][dj] + 1;
        }
    }
    return 999999;
}

int main(){
    cin >> R >> C;
    graph.resize(R);
    
    cin >> A >> B >> X >> Y;
    A--;B--;X--;Y--;

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> input;
            graph[i].push_back(input);
            if(input == '*'){
                dirt.push_back(make_pair(i,j));
            }
        }
    }

    min_count = Min(min_count,BFSTravel());
    for(int i=0;i<dirt.size();i++){
        graph[dirt[i].first][dirt[i].second] = '|';
        min_count = Min(min_count,BFSTravel());
        graph[dirt[i].first][dirt[i].second] = '-';
        min_count = Min(min_count,BFSTravel());
        graph[dirt[i].first][dirt[i].second] = '*';
    }

    if(min_count == 999999){
        cout << -1 << "\n";
    }
    else{
        cout << min_count << "\n";
    }
    return 0;
}