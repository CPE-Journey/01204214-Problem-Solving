#include <iostream>
using namespace std;

int main(){
    int n,input;
    cin >> n;
    int remaining = n;
    int order[n];
    int current[2][n];
    int get_same[n];
    int switcher = 1;

    for(int i=0;i<n;i++){
        cin >> input;
        order[i] = input-1;
        current[0][i] = i;
        current[1][i] = 0;
        get_same[i] = 0;
    }

    int round = 0;
    while(remaining>0){
        for(int i=0;i<n;i++){
            current[switcher][order[i]] = current[!switcher][i];
            if(current[switcher][i] == i && !get_same[i]){
                get_same[i] = 1;
                remaining--;
            }
        }
        switcher = !switcher;
        round++;
    }
    cout << round;
    return 0;
}

// Complexity Analysis => O(n^2)