#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,c,d,diff,fee=0,current=0;
vector<pair<int,int>> worklist;

int Max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> d >> c;
        worklist.push_back(make_pair(d,c));
    }

    sort(worklist.begin(),worklist.end());

    for(int i=0;i<N;i++){
        current += worklist[i].second;
        diff = current - worklist[i].first;
        if(diff > 10){
            fee = Max(fee,(diff-10)*1000);
        }
    }
    cout << fee << "\n";
    return 0;
}