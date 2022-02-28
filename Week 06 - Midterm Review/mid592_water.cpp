#include <iostream>
using namespace std;

int N,water=0,input,power=0;

int limit(int n,int lim){
    return n >= lim ? lim : n;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        if(water-input > 10){
            power += limit(limit(((water-input)*10),700),1000);
        }
        water = input;
    }
    cout << power << "\n";
    return 0;
}