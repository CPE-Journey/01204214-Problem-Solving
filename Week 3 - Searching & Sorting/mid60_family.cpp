#include <iostream>
#include <vector>
using namespace std;

int isAncestor(vector<int> v[],int anc,int dec){
    int sum = 0;
    for(int i=0;i<v[anc].size();i++){
        if(v[anc][i] == dec){
            return 1;
        }
        sum += isAncestor(v,v[anc][i],dec);
    }
    return sum == 0 ? 0 : 1;
}

int getAncestor(vector<int> v[],int a,int b){
    int resA = isAncestor(v,a,b),resB = isAncestor(v,b,a);
    if(resA) return a;
    else if(resB) return b;
    else return -1;
}

int main(){
    int N,M,input,n1,n2;
    cin >> N >> M;
    vector<int> family[N+1];

    for(int i=2;i<=N;i++){
        cin >> input;
        family[input].push_back(i);
    }

    for(int i=0;i<M;i++){
        cin >> n1 >> n2;
        cout << getAncestor(family,n1,n2) << "\n";
    }
    return 0;
}