#include <iostream>
#include <vector>
using namespace std;

int N,L,amount,day_count,len;
vector<int> day;

int main(){
    cin >> N;
    day.resize(N);

    for(int i=0;i<N;i++){
        cin >> L;
        for(int j=0;j<L;j++){
            cin >> amount >> day_count;
            
            if(day_count+i >= N){
                len = N;
            }
            else{
                len = day_count+i;
            }

            for(int k=i;k<len;k++){
                day[k] += amount;
            }
        }
    }

    for(int i=0;i<N;i++){
        cout << day[i] << "\n";
    }
    return 0;
}