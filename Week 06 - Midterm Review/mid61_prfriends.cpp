#include <iostream>
#include <vector>
using namespace std;

int A,B,count=0;

int isPrime(int n){
    if(n == 1)
        return 0;
    for(int i=2;i*i <= n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    cin >> A >> B;
    for(int i=A;i<=B;i++){
        if(isPrime(i) && isPrime(i+2) && i+2 <= B){
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}