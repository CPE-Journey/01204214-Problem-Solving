#include <iostream>
#include <vector>
using namespace std;

int K,N,C,P,W,A,max_weight=0,current_weight,lcount,cost,cheapest=-1;
vector<vector<int>> car;
vector<int> shippment;

int main(){
    cin >> K >> N;
    for(int i=0;i<K;i++){
        cin >> C >> P >> W;
        car.push_back({C,P,W});
    }
    for(int i=0;i<N;i++){
        cin >> A;
        shippment.push_back(A);
        if(A > max_weight){
            max_weight = A;
        }
    }

    for(int i=0;i<K;i++){
        if(max_weight > car[i][2]) continue;

        current_weight = car[i][2];
        lcount = 0;
        for(int j=0;j<N;j++){
            if(shippment[j] <= current_weight){
                current_weight -= shippment[j];
            }
            else{
                lcount++;
                current_weight = car[i][2] - shippment[j];
            }
        }
        cost = car[i][0] + car[i][1]*(lcount+1);
        if(cheapest == -1){
            cheapest = cost;
        }
        else if(cost < cheapest){
            cheapest = cost;
        }
    }

    cout << cheapest << "\n";
}