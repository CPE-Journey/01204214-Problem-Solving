#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,i,work_count=1;
long long int current,t1,t2;
vector<pair<int,int>> work;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> t1 >> t2;
        work.push_back(make_pair(t2,t1));
    }

    sort(work.begin(),work.end());

    current = work[0].first;
    for(int i=0;i<work.size();i++){
        if(work[i].second >= current){
            work_count++;
            current = work[i].first;
        }
    }

    cout << work_count << "\n";
    return 0;
}