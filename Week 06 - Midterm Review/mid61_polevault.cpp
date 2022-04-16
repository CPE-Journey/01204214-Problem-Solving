#include <iostream>
#include <vector>
using namespace std;

int N,Q,input,sum;
vector<int> pole,result;

int main(){
    cin >> N >> Q;
    result.push_back(3000001);
    for(int i=0;i<N;i++){
        cin >> input;
        pole.push_back(input);
    }
    for(int i=1;i<N-1;i++){
        sum = pole[i-1] + pole[i] + pole[i+1];
        result[sum] += 1;
        result[sum-pole[i+1]] += 1;
    }
    result[pole[N-1]+pole[N-2]] += 1;
    for(int i=0;i<Q;i++){
        cin >> input;
        if(result[input] != 0){
            cout << "Y";
        }
        else{
            cout << "N";
        }
    }
}