#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,s,f,w,max_weight,max_len = 0;
vector<pair<int,int>> worklist; // {finish,id};
vector<int> start,weight,memory;

int Max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> s >> f >> w;
        worklist.push_back(make_pair(f,i));
        start.push_back(s);
        weight.push_back(w);
        max_len = Max(max_len,f);
    }

    sort(worklist.begin(),worklist.end());
    memory.resize(max_len+1);

    for(int i=0;i<N;i++){
        for(int j=0;j<=start[worklist[i].second];j++){
            max_weight = Max(max_weight,memory[j]);
        }
        memory[worklist[i].first] = Max(memory[worklist[i].first],max_weight+weight[worklist[i].second]);
    }

    for(int i=0;i<max_len+1;i++){
        cout << memory[i] << " ";
        // for(int j=0;j<i;j++){
        //     max_weight = Max(max_weight,)
        // }
    }
}