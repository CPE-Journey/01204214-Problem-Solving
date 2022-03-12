#include <iostream>
#include <vector>
using namespace std;

int N,coin,result;
vector<int> memory,type = {1,5,10,25,50};

int main(){
    memory.resize(7490);
    memory[0] = 1;
    for(int j=0;j<5;j++){
        for(int i=1;i<=7489;i++){
            if(i >= type[j]){
                memory[i] += memory[i-type[j]];
            }
        }
    }
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> coin;
        cout << memory[coin] << "\n";
    }
}