#include <iostream>
#include <vector>
#include <list>
using namespace std;

void printGraph(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        cout << i << ": ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "\n";
}

void printList(list<int> q){
    for(auto i:q){
        cout << i << " ";
    }
    cout << "\n";
}