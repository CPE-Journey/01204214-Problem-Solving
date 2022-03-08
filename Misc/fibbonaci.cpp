#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long int> memory;

int main(){
    cin >> N;
    memory.resize(N+1);

    memory[1] = 1;
    memory[2] = 1;

    for(int i=3;i<=N;i++){
        memory[i] = memory[i-1] + memory[i-2];
    }
    cout << memory[N];
}