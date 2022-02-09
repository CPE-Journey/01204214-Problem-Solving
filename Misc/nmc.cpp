#include<iostream>
#include<vector>
#include <utility>
#include<algorithm>
using namespace std;

void minimalcov(){
    int M, L, R, current=0, count=0, index=0;
    vector<pair<int, int>> collect;
    vector<pair<int, int>> res;
    cin >> M;
    cin >> L >> R;
    while( L != 0 || R != 0){
        if(L <= M && R > 0){
            collect.push_back(make_pair(L, R));
        }
        cin >> L >> R;
    }
    
    if(collect.size() == 0){
        cout << 0 << "\n";
        return;
    }
    sort(collect.begin(), collect.end());
    while(index < collect.size() && current < M){
        res.push_back(make_pair(0, 0));
        // printf("Current %d Index %d %d %d\n",current,index,collect[index].first,collect[index].second);
        while(collect[index].first <= current){
            if(collect[index].second > res[count].second){
                res[count].first = collect[index].first;
                res[count].second = collect[index].second;
            }
            index++;
        }
        if(res[count].second == current){
            break;
        }
        current = res[count].second;
        count++;
    }
    if(current >= M){
        cout << count << "\n";
        for(int i=0; i<count; i++){
            cout << res[i].first << " " << res[i].second << "\n";
        }
    }
    else{
        cout << "0\n";
    }
    return;
}

int main(){
    int N;
    cin >> N;
    cout << "\n";
    for(int i=0; i<N; i++){
        minimalcov();
        cout << "\n";
    }
}