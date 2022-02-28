#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,Q,question,T,height_index,answer;
long long int min_height = 1000000001,input,shortest,tallest,tmp;
vector<int> order;
vector<long long int> height;

int main(){
    cin >> N >> Q;

    for(int i=0;i<N;i++){
        cin >> input;
        if(input < min_height){
            min_height = input;
            order.push_back(i+1);
            height.push_back(min_height);
        }
    }

    shortest = height[height.size()-1];
    tallest = height[0];

    order.push_back(N+1);
    height.push_back(0);

    for(int i=0;i<height.size()/2;i++){
        tmp = height[i];
        height[i] = height[height.size()-1-i];
        height[height.size()-1-i] = tmp;
    }

    for(int i=0;i<Q;i++){
        cin >> question >> T;
        if(question==1){
            height_index = upper_bound(order.begin(),order.end(),T)-order.begin()-1;
            cout << height[height.size()-1-height_index];
        }
        else{
            if(T < shortest){
                cout /* << "Cond 1 : " */ << N;
            }
            else if(T > tallest){
                cout /* << "Cond 2 : " */ << 0;
            }
            else{
                height_index = lower_bound(height.begin(),height.end(),T)-height.begin()-1;
                answer = order[order.size()-1-height_index];
                cout << answer-1;
            }
        }
        cout << "\n";
    }
    return 0;
}
