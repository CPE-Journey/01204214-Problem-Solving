#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int N,x,y,h1,h2;
double dist,totalDistance = 0;
vector<pair<int,int>> coordinate;
vector<pair<double,pair<int,int>>> graph;
vector<int> head,depth,visit;

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

double findDistance(int x1,int y1,int x2,int y2){
    int dx = x1-x2,dy = y1-y2;
    return sqrt((dx*dx)+(dy*dy));
}

int main(){
    cin >> N;

    for(int i=0;i<N;i++){
        head.push_back(i);
        depth.push_back(0);
        visit.push_back(0);
    }

    for(int i=0;i<N;i++){
        cin >> x >> y;
        coordinate.push_back(make_pair(x,y));
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) continue;
            dist = findDistance(coordinate[i].first,coordinate[i].second,coordinate[j].first,coordinate[j].second);
            graph.push_back(make_pair(dist,make_pair(i,j)));
        }
    }

    sort(graph.begin(),graph.end());

    int unionCount = 0,i=0;
    while(unionCount != N-2){
        h1 = findHead(graph[i].second.first);
        h2 = findHead(graph[i].second.second);

        if(h1 != h2){
            totalDistance += graph[i].first;
            unionHead(h1,h2);
            unionCount += 1;
        }
        i++;
    }

    printf("%.4f\n",totalDistance);
    return 0;
}