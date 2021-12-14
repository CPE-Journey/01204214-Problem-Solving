#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long int n,k;
    cin >> n >> k;
    int player_left = n;
    long int time[n];

    long int max_speed = 2000000000;
    for(int i=0;i<n;i++){
        cin >> time[i];
        if(time[i] < max_speed){
            max_speed = time[i];
        }
    }

    long int limit = max_speed*k;

    for(int i=0;i<n;i++){
        if(time[i]==max_speed) continue;
        if(k - limit/time[i] > 1 || limit%time[i] == 0){
            player_left--;
        }
    }
    cout << player_left;
    return 0;
}