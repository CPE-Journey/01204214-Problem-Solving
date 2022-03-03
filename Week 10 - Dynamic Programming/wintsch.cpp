#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,s,f,w,most_compat,max_len = 0,maximum_value=0,maximum_index=-1;
vector<pair<int,int>> worklist; // {finish,id};
vector<int> start,weight,memory,compatible;
vector<vector<int>> prevWork;

int Max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> N;
    prevWork.resize(N+1);
    for(int i=0;i<N;i++){
        cin >> s >> f >> w;
        worklist.push_back(make_pair(f,i));
        start.push_back(s);
        weight.push_back(w);
        max_len = Max(max_len,f);
    }

    sort(worklist.begin(),worklist.end());

    memory.resize(N+1);
    memory[N] = 0;

    for(int i=0;i<N;i++){
        most_compat = N;
        for(int j=i;j>=0;j--){
            if(worklist[j].first <= start[worklist[i].second]){
                most_compat = j;
                break;
            }
        }
        if(i > 0){
            if(memory[most_compat]+weight[worklist[i].second] > memory[i-1]){
            }
            else{
            }
            memory[i] = Max(memory[most_compat]+weight[worklist[i].second],memory[i-1]);
        }
        else{
            memory[i] = weight[worklist[i].second];
        }
        if(memory[i] > maximum_value){
            maximum_value = memory[i];
            maximum_index = i;
        }
        if(most_compat != N){
            for(int j=0;j<prevWork[most_compat].size();j++){
                prevWork[i].push_back(prevWork[most_compat][j]);
            }
        }
        prevWork[i].push_back(i);
    }
    cout << maximum_value << "\n";
    cout << prevWork[maximum_index].size() << "\n";
    for(int i=0;i<prevWork[maximum_index].size();i++){
        cout << worklist[prevWork[maximum_index][i]].second+1 << " ";
    }
    return 0;
}