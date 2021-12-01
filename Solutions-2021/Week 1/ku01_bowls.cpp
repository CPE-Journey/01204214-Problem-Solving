#include <iostream>
using namespace std;

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,count = 0,max_value,max_index,prev_max;
    cin >> n;

    int remaining = n;
    bool isFound;
    int dish[n];
    int counter[300];

    for(int i=0;i<n;i++){
        cin >> dish[i];
    }

    // Set Zero Counter
    for(int i=0;i<300;i++){
        counter[i] = 0;
    }

    for(int i=0;i<n;i++){
        counter[dish[i]]++;
        count = max(count, counter[dish[i]]);
    }

    cout << count;
    return 0;
}