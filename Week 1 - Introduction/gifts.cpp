#include <iostream>
using namespace std;

int main(){
    int n,input,sum = 0;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> input;
        if(input > 0){
            sum += input;
        }
    }

    cout << sum;
    return 0;
}