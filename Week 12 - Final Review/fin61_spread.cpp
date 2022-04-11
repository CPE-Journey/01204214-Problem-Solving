#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,u,v,input,h1,h2;
vector<int> head,depth,speed;
vector<pair<int,pair<int,int>>> edge;

int Ceil(int n,int d){
    int rem = n%d;
    int res = n/d;
    if(rem != 0){
        return res+1;
    }
    return res;
}

int findHead(int n){
    if(head[n]==n)
        return n;
    return findHead(head[n]);
}

void unionHead(int a,int b){
    if(depth[a] > depth[b]){
        head[b] = a;
    }
    else if(depth[a] < depth[b]){
        head[a] = b;
    }
    else{
        head[b] = a;
        depth[a] += 1;
    }
}

int Max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> input;
        head.push_back(i);
        depth.push_back(0);
        speed.push_back(input);
    }

    for(int i=0;i<M;i++){
        cin >> u >> v >> input;
        edge.push_back(make_pair(Ceil(input,speed[u-1]+speed[v-1]),make_pair(u-1,v-1)));
    }

    sort(edge.begin(),edge.end());

    int maxTime = 0,i=0,unionCount = 0;
    while(unionCount < N-1){
        h1 = findHead(edge[i].second.first);
        h2 = findHead(edge[i].second.second);
        
        if(h1 != h2){
            unionHead(h1,h2);
            unionCount += 1;
            maxTime = Max(maxTime,edge[i].first);
        }
        i++;
    }

    cout << maxTime << "\n";

    // for(int i=0;i<M;i++){
    //     printf("%d %d %d\n",edge[i].second.first,edge[i].second.second,edge[i].first);
    // }

}