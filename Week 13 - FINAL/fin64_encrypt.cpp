#include <iostream>
#include <list>
using namespace std;

int N,S,input;
list<int> code;

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++){
        cin >> input;
        code.push_back(input);
    }

    for(int i=1;i<=20-N;i++){
        code.push_back(i);
    }

    for(int i=0;i<S;i++){
        int last = code.back();
        code.push_front(last);
        code.pop_back();
    }

    auto start=code.begin();
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            auto start=code.begin();
            advance(start,i+5*j);
            cout << *start << " ";
        }
    }

    return 0;
}