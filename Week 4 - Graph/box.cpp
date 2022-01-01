#include <iostream>
#include <vector>
using namespace std;

int N,M;
char input;
bool isPossible;
vector<vector<char>> map;
vector<vector<int>> visit;

bool validPosition(int i,int j){
    if(j==M-1) return false;
    else if(map[i+1][j] != '#' && map[i][j+1] != '#' && map[i+1][j+1] != '#'){
        return true;
    }
    return false;
}

void travel(int si,int sj){
    // printGraph(visit);
    if(visit[si][sj] || map[si][sj] == '#' || !validPosition(si,sj)) return;
    visit[si][sj] = 1;

    if(si == N-1){
        // cout << " GO HERE\n";
        isPossible = true;
        return;
    }

    // Up
    if(si != 0){
        travel(si-1,sj);
    }

    // Down
    if(si != N-1){
        travel(si+1,sj);
    }

    // Left
    if(sj != 0){
        travel(si,sj-1);
    }

    // Right
    if(sj != M-1){
        travel(si,sj+1);
    }
}

bool startTravel(int start){
    isPossible = false;
    travel(0,start);
    return isPossible;
}

int main(){
    cin >> N >> M;
    map.resize(N+1);
    visit.resize(N,vector<int>(M));
    
    for(int i=0;i<N+1;i++){
        for(int j=0;j<M;j++){
            if(i==N){
                map[i].push_back('.');
            }
            else{
                cin >> input;
                map[i].push_back(input);
            }
        }
    }
    
    for(int i=0;i<M-1;i++){
        if(startTravel(i)){
            cout << "yes";
            return 0;
        }
    }
    cout << "no";
    return 0;
}