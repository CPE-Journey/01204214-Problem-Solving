#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,s,f,w,most_compat,max_len = 0,maximum_value=0,maximum_index=-1;
vector<pair<int,int>> worklist; // {finish,id};
vector<int> start,weight,memory,compatible;

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
    memory.resize(N+1);

    for(int i=0;i<N;i++){
        most_compat = N;
        // printf("START: %d\n",start[worklist[i].second]);
        for(int j=i;j>=0;j--){
            // printf("%d\n",worklist[j].first);
            if(worklist[j].first <= start[worklist[i].second]){
                // cout << "SELECTED\n";
                most_compat = j;
                break;
            }
        }
        if(i > 0){
            if(memory[most_compat]+weight[worklist[i].second]> memory[i-1]){
                cout << i << "\n";
            }
            memory[i] = Max(memory[most_compat]+weight[worklist[i].second],memory[i-1]);
        }
        else{
            memory[i] = weight[worklist[i].secon
            d];
        }
        
        compatible.push_back(most_compat);
        if(memory[i] > maximum_value){
            maximum_value = memory[i];
            maximum_index = i;
        }
    }

    // for(int i=0;i<N;i++){
    //     cout << compatible[i] << " ";
    // }

    // while(maximum_index != N){
    //     cout << maximum_index << "\n";
    //     maximum_index = compatible[maximum_index];
    // }
}