#include <iostream>
#include <vector>
#include <list>
using namespace std;

int N,Q,R,C,A,B;
char input;
vector<vector<char>> maze;
vector<vector<int>> walk = {{0,-1},{0,1},{1,0},{-1,0}};

void showMaze(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << maze[i][j];
        }
        cout << "\n";
    }
    cout << "============\n";
}

void travel(int si,int sj,int ti,int tj){
    int di,dj,key=1;
    list<vector<int>> Queue;
    vector<vector<int>> visit;
    visit.resize(N,vector<int>(N));

    Queue.push_back({si,sj});

    while(!Queue.empty()){
        di = Queue.front()[0];
        dj = Queue.front()[1];
        Queue.pop_front();

        if(maze[di][dj] == 'O'){
            if(!key)
                continue;
            else{
                key -= 1;
            }
        }
        else if(di == ti && dj == tj){
            cout << "yes\n";
            return;
        }

        if(di!=0 && maze[di-1][dj] != '#' && !visit[di-1][dj]){
            Queue.push_back({di-1,dj});
            visit[di-1][dj] = 1;
        };
        if(di!=N-1 && maze[di+1][dj] != '#' && !visit[di+1][dj]){
            Queue.push_back({di+1,dj});
            visit[di+1][dj] = 1;
        };
        if(dj!=0 && maze[di][dj-1] != '#' && !visit[di][dj-1]){
            Queue.push_back({di,dj-1});
            visit[di][dj-1] = 1;
        };
        if(dj!=N-1 && maze[di][dj+1] != '#' && !visit[di][dj+1]){
            Queue.push_back({di,dj+1});
            visit[di][dj+1] = 1;
        };
    }
    cout << "no\n";
}

int main(){
    cin >> N >> Q;
    maze.resize(N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> input;
            maze[i].push_back(input);
        }
    }

    for(int i=0;i<Q;i++){
        cin >> R >> C >> A >> B;
        travel(R-1,C-1,A-1,B-1);
    }

}