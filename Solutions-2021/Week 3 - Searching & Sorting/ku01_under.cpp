#include <iostream>
using namespace std;

int max(int a,int b){
    return a > b ? a : b;
}

int inBetween(int p,int a,int b){
    return p >= a && p < b ? 1 : 0;
}

int main(){
    int L,N;
    cin >> L >> N;
    int bridge[N][2];
    int count,max_under = 0;
    for(int i=0;i<N;i++){
        cin >> bridge[i][0] >> bridge[i][1];
    }
    for(int i=0;i<L;i++){
        count = 0;
        for(int j=0;j<N;j++){
            if(inBetween(i,bridge[j][0],bridge[j][1])){
                count += 1;
            }
        }
        max_under = max(max_under,count);
    }
    cout << max_under;
}