#include <iostream>
#include <vector>
using namespace std;

int N,res,input;
vector<int> memory,banana;

int Max(int a,int b){
    return a > b ? a : b;
}

int countBanana(int start){
    if(start < 2){
        return 0;
    }
    else if(memory[start] != -1){
        return memory[start];
    }
    res = Max(countBanana(start-1),countBanana(start-3)+banana[start]);
    memory[start] = res;
    return res;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        banana.push_back(input);
        memory.push_back(-1);
    }

    cout << countBanana(N-1);
    return 0;
}