#include <iostream>
#include <vector>
using namespace std;

int N,res,input;
vector<int> memory,banana;

int Max(int a,int b){
    return a > b ? a : b;
}

int absuluteZero(int n){
    return n < 0 ? 0 : n;
}

int countBanana(){
    for(int i=2;i<N;i++){
        memory[i] = Max(memory[absuluteZero(i-1)],memory[absuluteZero(i-3)]+banana[i]);
    }
    return memory[N-1];
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        banana.push_back(input);
        memory.push_back(0);
    }

    cout << countBanana();
}