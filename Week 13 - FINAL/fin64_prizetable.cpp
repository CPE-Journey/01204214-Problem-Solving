#include <iostream>
#include <vector>
using namespace std;

int N,M,K,maxPrize=0,input;
vector<vector<int>> table;
vector<vector<vector<int>>> optimal;

int Max2(int a,int b){
    return a > b ? a : b;
}

int Max3(int a,int b,int c){
    return Max2(a,Max2(b,c));
}

int findOpt(int i,int j,int k){
    if(i < 0 || i >= N || j < 0 || j >= M) return 0;
    if(optimal[i][j][k] != 0){
        return optimal[i][j][k];
    }
    if(k > 0){
        optimal[i][j][k] = table[i][j]+Max3(findOpt(i-1,j-1,k-1),findOpt(i-1,j,k),findOpt(i-1,j+1,k-1));
        return optimal[i][j][k];
    }
    optimal[i][j][k] = table[i][j]+findOpt(i-1,j,k);
    return optimal[i][j][k];
}

int main(){
    cin >> N >> M >> K;
    optimal.resize(N,vector<vector<int>>(M,vector<int>(K+1)));
    table.resize(N);

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> input;
            table[i].push_back(input);
        }
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<=K;j++){
            optimal[0][i][j] = table[0][i];
        }
    }

    for(int i=0;i<M;i++){
        maxPrize = Max2(maxPrize,findOpt(N-1,i,K));
    }
    cout << maxPrize;
    return 0;
}