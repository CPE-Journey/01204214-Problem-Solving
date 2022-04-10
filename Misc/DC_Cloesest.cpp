#include <iostream>
#include <vector>
using namespace std;

int N,M;

int Closest(int arr[],int i,int j){
    int x,y;
    if(i == j){
        return arr[i];
    }
    x = Closest(arr,i,(i+j)/2);
    y = Closest(arr,((i+j)/2)+1,j);
    if(abs(x-M) < abs(y-M)){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    cin >> N >> M;
    int A[N];

    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    cout << Closest(A,0,N-1);
}