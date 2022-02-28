#include <iostream>
#include <vector>
using namespace std;

int N = 12,mx;
vector<int> A,P = {1,2,5,4,3,0,6,1,2,7,2,1};

int main(){
    A.resize(N);
    for(int i=3;i<N;i++){
        mx = A[i-3];
        for(int j=0;j<i-3;j++){
            if(A[j] > mx){
                mx = A[j];
                // cout << mx << "\n";
            }
        }
        A[i] = P[i] + mx;
    }
    
    for(int i=0;i<N;i++){
        cout << A[i] << " ";
    }
}