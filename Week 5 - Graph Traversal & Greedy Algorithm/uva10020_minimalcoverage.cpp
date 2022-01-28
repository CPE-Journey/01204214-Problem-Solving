#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,M,L=0,R=0,min_range=999999,dt;
vector<pair<int,int>> work;
vector<int> answer;

int main(){
    cin >> M;
    while(true){
        cin >> L >> R;
        if(!L && !R){
            break;
        }

        if(R <= 0 || L >= M) continue;


        if(L < 0){
            L = 0;
        }
        if(R > M){
            R = M;
        }
        work.push_back(make_pair(R,L));
        
    }

    sort(work.begin(),work.end());

    for(int i=0;i<work.size();i++){
        if
    }

    // for(int i=0;i<work.size();i++){
    //     cout << work[i].first << " " << work[i].second.first << " " << work[i].second.second << "\n";
    // }
    // cout << answer[0] << " " << answer[1];
}