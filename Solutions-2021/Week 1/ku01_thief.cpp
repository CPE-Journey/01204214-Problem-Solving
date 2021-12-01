#include <iostream>
using namespace std;

int main(){
    int n,k,t,count = 0;
    cin >> n >> k >> t;
    int holder = 1;
    int held[n];
    bool initial = true;

    for(int i=0;i<n;i++){
        held[i] = 0;
    }

    while((holder!=1 || initial) && holder != t){
        initial = false;
        if(held[holder]!=-1){
            held[holder] = -1;
            count++;
        }
        holder = (holder+k)%n;
    }
    if(holder == t){
        count++;
    }
    cout << count;
    return 0;
}