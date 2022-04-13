#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int n,d,x,y,testcase=1;
vector<pair<double,double>> island;

int main(){
    while(1){
        cin >> n >> d;
        if(!n && !d) return 0;
        int isPossible = 1;
        island.clear();
        for(int i=0;i<n;i++){
            cin >> x >> y;
            if(y > d){
                isPossible = 0;
            }
            else{
                island.push_back(make_pair(x-sqrt(d*d-y*y),x+sqrt(d*d-y*y)));
            }
        }
        sort(island.begin(),island.end());
        int i=0,current=-9999999,count=0;
        while(i < n){
            while(i < n && island[i].first <= current){
                current = current < island[i].second ? current : island[i].second;
                i++;
            }
            count += 1;
            current = island[i].second;
        }
        if(!isPossible){
            count = 0;
        }
        printf("Case %d: %d\n",testcase,count-1);
        testcase += 1;
    }
}
