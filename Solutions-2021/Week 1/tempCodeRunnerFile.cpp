#include <iostream>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int player_left = n;
    long int time[n];// = {6,7,15,9,11};
    int knock[n];// = {0,0,0,0,0};

    long int max_speed = 2000000000;
    for(int i=0;i<n;i++){
        cin >> time[i];
        if(time[i] < max_speed){
            max_speed = time[i];
        }
        knock[i] = 0;
    }
    // cout << max_speed << "\n";
    for(int r=1;r<=k+1;r++){
        for(int i=0;i<n;i++){
            if(!knock[i] && (time[i]*r/max_speed)-r > 1){
                knock[i] = 1;
                player_left--;
                // cout << "Player Out: " << i+1 << " at Round " << r << "\n";
            }
        }
    }
    cout << player_left;
}