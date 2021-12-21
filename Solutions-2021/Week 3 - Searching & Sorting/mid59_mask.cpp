#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int data;
    int number;
}Player;

vector<int> getWinner(vector<int> v,int round){
    vector<int> rtn;
    int max_value = 0,max_index = 0;
    for(int i=0;i<v.size();i++){
        if(v[i] > max_value){
            max_value = v[i];
            max_index = i+1;
        }
    }
    rtn.push_back(max_value);
    rtn.push_back(max_index+(v.size()*round));
    return rtn;
}

vector<int> max(vector<int> a,vector<int>b){
    return a[0] > b[0] ? a : b;
}

vector<int> min(vector<int> a,vector<int>b){
    return a[0] < b[0] ? a : b;
}

void printWinner(vector<vector<int>> v){
    int secondA = min(v[0],v[1])[1];
    int secondB = min(v[2],v[3])[1];
    vector<int> firstA = max(v[0],v[1]);
    vector<int> firstB = max(v[2],v[3]);
    if(firstA[0] > firstB[0]){
        cout << firstA[1] << " " << firstB[1] << " ";
    }
    else{
        cout << firstB[1] << " " << firstB[0] << " ";
    }
    cout << secondA << " " << secondB << "\n";
}

int main(){
    int N,skill;
    cin >> N;
    vector<int> coder;
    vector<vector<int>> winner;

    for(int i=0;i<4;i++){
        coder.clear();
        for(int j=0;j<N;j++){
            cin >> skill;
            coder.push_back(skill);
        }
        winner.push_back(getWinner(coder,i));
    }
    printWinner(winner);
    return 0;
}