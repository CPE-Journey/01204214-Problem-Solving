#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,M,L,R,dt,current,d1,d2;

void minimalCoverage(){
    vector<pair<int,int>> work,answer;
    cin >> M;

    while(true){
        cin >> L >> R;
        if(L==0 && R==0){
            break;
        }
        if(R <= 0 || L >= M) continue;
        d1 = L;
        d2 = R;
        if(L < 0){
            d1 = 0;
        }
        if(R > M){
            d2 = M;
        }

        work.push_back(make_pair(L,R));
    }

    sort(work.begin(),work.end());

    current = 0;
    pair<int,int> select;
    select.first = 0;
    select.second = 0;

    int i=0;
    while(current < M && i < work.size()){
        select.first = 0;
        select.second = 0;
        while(work[i].first <= current){
            if(work[i].second > select.second){
                select.first = work[i].first;
                select.second = work[i].second;
            }
            i++;
        }
        if(select.second == current) break;
        current = select.second;
        answer.push_back(make_pair(select.first,select.second));
    }
    if(current >= M){
        cout << answer.size() << "\n";
        for(int i=0;i<answer.size();i++){
            cout << answer[i].first << " " << answer[i].second << "\n";
        }
    }
    else{
        cout << "0\n";
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        minimalCoverage();
        cout << "\n";
    }
}