#include <iostream>
#include <vector>
using namespace std;

int N,M,area,level2=0,level1=0;
char input;
bool foundOre,foundForest;
vector<vector<char>> map;
vector<vector<int>> visit;

void travel(int si,int sj){
    if(map[si][sj] == '#' || visit[si][sj]) return;
    else if(map[si][sj] == '$'){
        foundOre = true;
    }
    else if(map[si][sj] == '*'){
        foundForest = true;
    }

    visit[si][sj] = 1;
    area++;

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

void startJourney(int si,int sj){
    foundOre = false;
    foundForest = false;
    area = 0;
    travel(si,sj);
    if(foundOre && foundForest){
        level2 += area;
    }
    else if(foundOre || foundForest){
        level1 += area;
    }
}

int main(){
    cin >> N >> M;
    
    map.resize(N);
    visit.resize(N,vector<int>(M));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> input;
            map[i].push_back(input);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j] == '#' || visit[i][j]) continue;
            startJourney(i,j);
        }
    }
    
    cout << level2 << " " << level1;
    return 0;
}