#include <iostream>
#include <vector>
using namespace std;

int N,M,input,current=0;
bool alreadyWin = false;
vector<int> board = {0};

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> input;
        board.push_back(input);
    }

    for(int i=0;i<M;i++){
        cin >> input;

        if(alreadyWin) continue;

        current += input;
        current += board[current];

        if(current >= N){
            alreadyWin = true;
            current = N;
        }
        else if(current < 0) current = 0;
    }

    cout << current << "\n";
    return 0;
}
