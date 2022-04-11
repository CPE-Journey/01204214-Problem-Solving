#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int N, x, y, X1, X2, Y1, Y2, res;
double w;
vector<pair<int, int>> mine;
vector<pair<double, pair<int, int>>> mine_wt;
vector<int> parent, rnk;

int find(int n){
    if (n == parent[n]){
        return n; 
    }
    return find(parent[n]);
}

void Union(int x, int y){
    if (rnk[x] == rnk[y]){
        parent[y] = x;
        rnk[y]++;
    }
    if (rnk[x] > rnk[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
    }
}

double mst(){
    double mst_weight = 0;
    int count=0, j=0;
    sort(mine_wt.begin(), mine_wt.end());
    while(count < N-2){
        cout << mine_wt[j].second.first << "\n";
        int tmp_u = find(mine_wt[j].second.first);
        cout << "X\n";
        int tmp_v = find(mine_wt[j].second.second);
        cout << "X\n";
        cout << tmp_u << " " << tmp_v << "\n";
        cout << "X\n";
        if (tmp_u != tmp_v){
            cout << "X\n";
            mst_weight += mine_wt[j].first;
            cout << "X\n";
            Union(tmp_u, tmp_v);
            cout << "X\n";
            count++;
            cout << "X\n";
        }
        cout << "X\n";
        j++;
        cout << "X\n";
        cout << mst_weight << "\n";
        cout << "-------\n";
    }
    return mst_weight;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> x >> y;
        mine.push_back(make_pair(x, y));
    }

    for(int j=0; j<N; j++){
        for(int k=0; k<N; k++){
            if(j == k){
                continue;
            }
            X1= mine[j].first;
            X2 = mine[k].first;
            Y1 = mine[j].second;
            Y2 = mine[k].second;
            w = sqrt(pow(X1-X2, 2)+ pow(Y1-Y2, 2));
            mine_wt.push_back(make_pair(w, make_pair(j, k)));
        }
    }

    for (int i = 0; i <= N; i++){
        rnk.push_back(0);
        parent.push_back(i);
    }
    
    res = mst();
    printf("%.5f", res);
}