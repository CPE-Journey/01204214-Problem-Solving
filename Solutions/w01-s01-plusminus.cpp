#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int operand[n];
    char opr[n-1];

    int ininp;
    char chinp;

    for(int i=0;i<n;i++){
        cin >> ininp;
        operand[i] = ininp;
        if(i == n-1) continue;
        cin >> chinp;
        opr[i] = chinp;
    }

    int result = operand[0];
    for(int i=0;i<n-1;i++){
        if(opr[i] == '+'){
            result += operand[i+1];
        }
        else if(opr[i] == '-'){
            result -= operand[i+1];
        }
    }

    cout << result;
    return 0;
}