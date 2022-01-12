#include <iostream>
#include <vector>
using namespace std;

int N,input,new_pair;
vector<vector<int>> favourite;
vector<int> match;

void printMatrix(vector<vector<int>> m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout << m[i][j] << " ";
        }
        cout << "\n";
    }
}

int better(vector<int> v,int a,int b){
    for(int i=0;i<v.size();i++){
        if(v[i] == a){
            return a;
        }
        else if(v[i] == b){
            return b;
        }
    }
    return -1;
}

int main(){
    cin >> N;

    favourite.resize(2*N);
    match.resize(2*N);

    for(int i=0;i<N*2;i++){
        for(int j=0;j<N;j++){
            cin >> input;
            favourite[i].push_back(input-1);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!match[favourite[i][j]]){
                match[i] = favourite[i][j];
                match[favourite[i][j]] = i;
            }
            else{
                new_pair = better(favourite[j],match[j],i);
                match[i] = favourite[i][j];
                match[favourite[i][j]] = i;
            }
        }
    }
}