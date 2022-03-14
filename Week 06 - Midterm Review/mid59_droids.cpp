#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,selected,disable=-1;
long long int total_distance=0,input;
vector<long long int> droid; // 10 20 40 55 80

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> input;
        droid.push_back(input);
    }
    sort(droid.begin(),droid.end());
    for(int i=0;i<M;i++){
        cin >> input;
        selected = upper_bound(droid.begin(),droid.end(),input)-droid.begin()-1;
        // printf("SELECT: %d\n",selected);
        if(selected == disable){
            // cout << "NO\n";
            long long int lower = 2000000001;
            long long int upper = 2000000001;
            if(selected != 0){
                lower = abs(droid[selected-1]-input);
            }
            if(selected < N){
                upper = abs(droid[selected+1]-input);
            }
            if(lower < upper){
                total_distance += lower;
                // printf("+%d (Now %d)\n",lower,total_distance);
                disable = selected-1;
            }
            else{
                total_distance += upper;
                // printf("+%d (Now %d)\n",upper,total_distance);
                disable = selected+1;
            }
            // printf("%d %d %d\n",selected,lower,upper);
        }
        else{
            total_distance += abs(droid[selected]-input);
            // printf("+%d (Now %d)\n",abs(droid[selected]-input),total_distance);
            disable = selected;
        }
    }
    cout << total_distance << "\n";
    // for(int i=0;i<droid.size();i++){
    //     cout << droid[i] << " ";
    // }
}