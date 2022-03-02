#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

typedef struct work{
    int start,finish,weight;

    bool operator<(work& a,work& b){
        return a
    }
}work;

int N,s,f,w;

int main(){
    cin >> N;
    work worklist[N];

    for(int i=0;i<N;i++){
        cin >> s >> f >> w;
        worklist[i] = {s,f,w};
    }

    for(int i=0;i<N;i++){
        printf("%d %d %d\n",worklist[i].start,worklist[i].finish,worklist[i].weight);
    }
}