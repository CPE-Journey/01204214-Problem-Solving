#include <iostream>
#include <vector>
using namespace std;

int C,N,K,p1,p2;
vector<vector<int>> monster;
vector<vector<int>> optimal;

int Min(int a,int b){
    return a > b ? b : a;
}

int findOPT(int n,int t,int k){
    printf("%d %d %d\n",n,t,k);
    if(k < 0 || k > 2*K){
        cout << "NO\n";
        return 9999999;
    }
    if(n==0){
        optimal[n][k] = Min(monster[n][0],monster[n][1]);
        cout << "=== 1 " << optimal[n][k] << "\n";
        return optimal[n][k];
    }
    if(optimal[n][k] != 9999999){
        cout << "=== 2 " << optimal[n][k] << "\n";
        return optimal[n][k];
    }
    optimal[n][k] = Min(monster[n][0] + findOPT(n-1,0,k-1),monster[n][1] + findOPT(n-1,1,k+1));
    cout << "=== 3 " << optimal[n][k] << "\n";
    return optimal[n][k];
}

int main(){
    cin >> N >> K;
    monster.clear();
    optimal.clear();
    optimal.resize(N,vector<int>(2*K+1));

    for(int i=0;i<N;i++){
        for(int k=0;k<2*K+1;k++){
            optimal[i][k] = 9999999;
        }
    }

    for(int i=0;i<N;i++){
        cin >> p1 >> p2;
        monster.push_back({p1,p2});
    }
    cout << findOPT(N-1,1,K+1);
//     for(int i=0;i<N;i++){
//         for(int j=0;j<optimal[i].size();j++){
//             cout << optimal[i][j] << " ";
//         }
//         cout << '\n';
//     }
}