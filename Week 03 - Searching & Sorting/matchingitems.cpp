#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Q,select,price;
    cin >> N >> Q;
    vector<int> itemPrice;

    for(int i=1;i<=N;i++){
        cin >> price;
        itemPrice.push_back(price);
    }
    for(int i=0;i<Q;i++){
        cin >> select >> price;
        select--;
        cout << (upper_bound(itemPrice.begin(),itemPrice.end(),itemPrice[select]+price)-itemPrice.begin()) << "\n";
    }
    return 0;
}