#include <iostream>
#include <vector>
using namespace std;

int C,N,K,p1,p2;
vector<pair<int,int>> monster;
vector<vector<int>> optimal;

int Min(int a,int b){
    return a > b ? b : a;
}

int findOPT(int n,int t,int k){
    if(n==0){
        // cout << "2" << "\n";
        optimal[n][t] = t == 2 ? monster[n].second : monster[n].first;
        return optimal[n][t];
    }
    if(optimal[n][t] != 9999999){
        return optimal[n][t];
    }
    if(k >= K){
        optimal[n][t] = Min(monster[n].first,monster[n].second) + findOPT(n-1,1,k-1);
        return optimal[n][t];
    }
    if(k <= -K){
        optimal[n][t] = Min(monster[n].first,monster[n].second) + findOPT(n-1,2,k+1);
        return optimal[n][t];
    }
    optimal[n][t] = Min(Min(monster[n].first,monster[n].second) + findOPT(n-1,1,k-1),Min(monster[n].first,monster[n].second) + findOPT(n-1,2,k+1));
    return optimal[n][t];
}

int main(){
    cin >> C;
    // C = 1;
    for(int j=0;j<C;j++){
        optimal.clear();
        monster.clear();
        cin >> N >> K;
        optimal.resize(N);
        for(int i=0;i<N;i++){
            cin >> p1 >> p2;
            monster.push_back(make_pair(p1,p2));
            optimal[i].push_back(9999999);
            optimal[i].push_back(9999999);
        }
        cout << findOPT(N-1,1,0) << "\n";
    }
    for(int i=0;i<N;i++){
        cout << optimal[i][0] << " " << optimal[i][1] << "\n";
    }
}