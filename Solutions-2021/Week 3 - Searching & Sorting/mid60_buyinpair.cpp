#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,A,B,input,count = 0;
    cin >> N >> A >> B;
    vector<int> price;

    for(int i=0;i<N;i++){
        cin >> input;
        price.push_back(input);
    }

    for(int i=0;i<price.size();i++){
        for(int j=i+1;j<price.size();j++){
            if(price[i]+price[j] >= A && price[i]+price[j] <= B){
                count++;
            }
        }
    }
    cout << count;
    return 0;
}
