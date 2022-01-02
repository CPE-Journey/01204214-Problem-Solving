#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int N,A,B,input,count = 0,high,low;
    cin >> N >> A >> B;
    vector<long long int> price;

    for(int i=0;i<N;i++){
        cin >> input;
        price.push_back(input);
    }

    sort(price.begin(),price.end());

    for(int i=0;i<N;i++){
        if(price[i] > B){
            break;
        }
        else if(price[i] < A){
            low = lower_bound(price.begin()+i+1,price.end(),A-price[i])-price.begin();
            high = upper_bound(price.begin()+i+1,price.end(),B-price[i])-price.begin()-1;
        }
        else{
            low = i+1;
            high = upper_bound(price.begin()+i,price.end(),B-price[i])-price.begin()-1;
        }
        if(high >= low){
            count += high-low+1;
        }
    }

    cout << count;
    return 0;
}
