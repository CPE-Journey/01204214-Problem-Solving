#include <iostream>
#include <list>
using namespace std;

list<int> x;

// Pointer

int main(){
    x.push_back(5);
    x.push_back(10);
    x.push_back(41);
    x.push_back(12);
    x.push_back(1);
    x.push_back(22);
    // begin , front
    // end   , back
    for(auto i=x.begin();i != x.end();i++){
        cout << *i << " ";
    }

    cout << "\n";

    for(auto i:x){
        cout << i << " ";
    }
}