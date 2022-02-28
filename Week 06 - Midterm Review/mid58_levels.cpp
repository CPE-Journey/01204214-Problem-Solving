#include <iostream>
#include <vector>
using namespace std;

int N,M,A,B,C,level = 1;
vector<vector<int>> requirement;
vector<int> passed = {0,0,0};

int main(){
    cin >> N >> M;
    for(int i=0;i<N-1;i++){
        cin >> A >> B >> C;
        requirement.push_back({A,B,C});
    }
    for(int i=0;i<M;i++){
        cin >> A >> B >> C;

        if(requirement[level-1][0] <= A){
            passed[0] = 1;
        }
        if(requirement[level-1][1] <= B){
            passed[1] = 1;
        }
        if(requirement[level-1][2] <= C){
            passed[2] = 1;
        }

        if(passed[0] && passed[1] && passed[2]){
            passed[0] = 0;
            passed[1] = 0;
            passed[2] = 0;
            level++;
        }

        if(level == N)
            break;
    }
    cout << level << "\n";
    return 0;
}