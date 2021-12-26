#include <iostream>
#include<bits/stdc++.h> 
using namespace std;

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int value;
    vector<int> v1 = {20, 30, 40, 25, 15};

    swap(v1[0],v1[2]);
    cout << v1[0];

    // long long int N,A,B,input,count = 0;
    // cin >> N >> A >> B;
    // vector<long int> price;

    // for(int i=0;i<N;i++){
    //     cin >> input;
    //     price.push_back(input);
    // }

    // for(int i=0;i<price.size();i++){
    //     for(int j=i+1;j<price.size();j++){
    //         if(price[i]+price[j] >= A && price[i]+price[j] <= B){
    //             count++;
    //         }
    //     }
    // }
    // cout << count;
    // return 0;
}
