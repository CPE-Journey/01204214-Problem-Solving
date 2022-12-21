#include <iostream>
#include <vector>
using namespace std;

int N,input,sum;
vector<int> restaurant,price;

int isIncluded(vector<int> lst,int x){
    for(int i=0;i<lst.size();i++){
        if(lst[i] == x){
            return 1;
        }
    }
    return 0;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        restaurant.push_back(input);
    }
    
    for(int i=0;i<N;i++){
        sum = 0;
        for(int j=i;j<N;j++){
            sum += restaurant[j];
            if(!isIncluded(price,sum)){
                price.push_back(sum);
            }
        }
    }

    cout << price.size() << "\n";
    return 0;
}