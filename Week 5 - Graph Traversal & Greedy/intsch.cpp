#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,i,work_count=1;
long long int current,t1,t2;
vector<pair<long long int,long long int>> work;

void printVector(vector<pair<long long int,long long int>> v){
    for(int i=0;i<v.size();i++){
        cout << v[i].first << " " << v[i].second << "\n";
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> t1 >> t2;
        work.push_back(make_pair(t1,t2));
    }

    sort(work.begin(),work.end());
    cout<<"\n";
    // printVector(work);

    current = work[0].second;
    for(int i=0;i<work.size();i++){
        if(work[i].second > current && work[i].first >= current){
            work_count++;
            current = work[i].second;
        }
    }

    cout << work_count << "\n";
    return 0;
}