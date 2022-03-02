#include <iostream>
#include <vector>
#include <list>
using namespace std;

int R,C,di,dj,A=1,B=1,X=3,Y=1,min_count=999999,count;
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

void BFSTravel(){
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

        if(graph[di][dj] != '.') continue;
        else if(di == X && dj == Y){
            cout << level[di][dj];
            return;
        }

        if(di != 0 && !visited[di-1][dj]){
            Queue.push_back(make_pair(di-1,dj));
            visited[di-1][dj] = 1;
            level[di-1][dj] = level[di][dj] + 1;
        }
        if(di != R-1 && !visited[di+1][dj]){
            Queue.push_back(make_pair(di+1,dj));
            visited[di+1][dj] = 1;
            level[di+1][dj] = level[di][dj] + 1;
        }
        if(dj != 0 && !visited[di][dj-1]){
            Queue.push_back(make_pair(di,dj-1));
            visited[di][dj-1] = 1;
            level[di][dj-1] = level[di][dj] + 1;
        }
        if(dj != C-1 && !visited[di][dj+1]){
            Queue.push_back(make_pair(di,dj+1));
            visited[di][dj+1] = 1;
            level[di][dj+1] = level[di][dj] + 1;
        }
        // printVector(visited);
    }
    cout << "Impossible\n";
}

int main(){
    cin >> R >> C;
    graph.resize(R);
    
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> input;
            graph[i].push_back(input);
            if(input == '*'){
                dirt.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0;i<dirt.size();i++){
        graph[dirt[i].first][dirt[i].second] = '.';
        BFSTravel();
        graph[dirt[i].first][dirt[i].second] = '*';
    }

}