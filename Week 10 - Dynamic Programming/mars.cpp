#include <iostream>
#include <vector>
using namespace std;

int T,current[]={0,0};
string input;

char getLetter(int index){
    return (char)(index+65);
}

int getIndex(char letter){
    return ((int)letter) - 65;
}

pair<int,int> direction(int plate,int n){
    int diff = current[plate]-n;
    return abs(diff)%26 > abs(diff+26)%26;
}

int main(){
    cin >> T;

    for(int i=0;i<T;i++){
        cin >> input;
        for(int j=0;j<input.length();j++){

        }
    }
}