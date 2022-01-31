#include <iostream>
#include <vector>
using namespace std;

int N,f,max_eat=0,res;
vector<int> food,diff;

int setPositive(int n){
    return n < 0 ? N+n : n;
}

int main(){
    cin >> N;
    diff.resize(N);
    for(int i=0;i<N;i++){
        cin >> f;
        food.push_back(f);
    }

    for(int i=0;i<N;i++){
        res = setPositive(food[i]-i);
        diff[res] += 1;
        if(diff[res] > max_eat){
            max_eat = diff[res];
        }
    }

    cout << max_eat << "\n";
    return 0;
}