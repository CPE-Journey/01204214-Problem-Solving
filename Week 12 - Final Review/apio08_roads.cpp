#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N,M,K,u,v,c,freeCount=0,h1,h2,select_index=0;

vector<pair<int,int>> rock,concrete;
vector<vector<int>> selected;
vector<int> head,depth,visit;

int getHead(int n){
    return head[n] == n ? n : getHead(head[n]);
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

int main(){
    cin >> N >> M >> K;
    
    for(int i=0;i<N;i++){
        head.push_back(i);
        depth.push_back(0);
        visit.push_back(0);
    }
    selected.resize(N);

    for(int i=0;i<M;i++){
        cin >> u >> v >> c;
        if(c == 0){
            rock.push_back(make_pair(u-1,v-1));
            freeCount += 1;
        }
        else{
            concrete.push_back(make_pair(u-1,v-1));
        }
    }

    if(freeCount < K){
        cout << "no solution\n";
        return 0;
    }

    int current = K;
    for(int i=0;i<rock.size();i++){
        if(current == 0) break;
        h1 = getHead(rock[i].first);
        h2 = getHead(rock[i].second);
        if(h1 != h2){
            unionHead(h1,h2);
            current -= 1;
            selected[select_index].push_back(rock[i].first+1);
            selected[select_index].push_back(rock[i].second+1);
            selected[select_index].push_back(0);
            select_index++;
            // printf("%d %d 0\n",rock[i].first+1,rock[i].second+1);
            visit[rock[i].first] = 1;            
            visit[rock[i].second] = 1;
        }
    }

    if(current != 0){
        cout << "no solution\n";
        return 0;
    }

    for(int i=0;i<concrete.size();i++){
        h1 = getHead(concrete[i].first);
        h2 = getHead(concrete[i].second);
        if(h1 != h2){
            unionHead(h1,h2);
            selected[select_index].push_back(concrete[i].first+1);
            selected[select_index].push_back(concrete[i].second+1);
            selected[select_index].push_back(1);
            select_index++;
            // printf("%d %d 1\n",concrete[i].first+1,concrete[i].second+1);
            visit[concrete[i].first] = 1;
            visit[concrete[i].second] = 1;
        }
    }
    
    for(int i=0;i<N;i++){
        if(!visit[i]){
            cout << "no solution\n";
            return 0;
        }
    }

    for(int i=0;i<select_index;i++){
        printf("%d %d %d\n",selected[i][0],selected[i][1],selected[i][2]);
    }
}