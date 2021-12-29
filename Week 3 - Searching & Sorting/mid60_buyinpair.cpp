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
            cout << "Less than " << "A = " << A -price[i] << " | B = " << B - price[i] << " ";
            low = upper_bound(price.begin(),price.end(),A-price[i])-price.begin();
            high = lower_bound(price.begin(),price.end(),B-price[i])-price.begin()-1;
        }
        else{
            cout << "Between ";
            low = upper_bound(price.begin(),price.end(),price[i]-A)-price.begin();
            high = lower_bound(price.begin(),price.end(),B-price[i])-price.begin()-1;
        }
        cout << low << " " << high << "\n";
        count += high-i+1;
    }

    cout << count;

    // for(int i=0;i<price.size();i++){
    //     for(int j=i+1;j<price.size();j++){
    //         if(price[i]+price[j] >= A && price[i]+price[j] <= B){
    //             count++;
    //         }
    //     }
    // }
    // cout << count;
    return 0;
}
