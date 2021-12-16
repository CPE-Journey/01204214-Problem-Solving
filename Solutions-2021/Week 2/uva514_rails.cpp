#include <iostream>
#include <list>
using namespace std;

int main() {
    int N,coach,current;
    list<int> station;
    bool reset;
    while(true){
        reset = false;
        cin >> N;
        if(N==0){
            break;
        }
        while(true){
            current = 1;
            while(!station.empty()){
                station.pop_back();
            }
            for(int i=1;i<=N;i++){
                cin >> coach;
                if(coach == 0){
                    cout << "\n";
                    reset = true;
                    break;
                }
                if(!station.empty() && station.back()==coach){
                    station.pop_back();
                }
                else{
                    for(int j=current;j<=N;j++){
                        if(coach == j){
                            current++;
                            break;
                        }
                        station.push_back(j);
                        current++;
                    }
                    
                }
            }
            if(reset){
                break;
            }
            else if(station.empty()){
                cout << "Yes\n";
            }
            else{
                cout << "No\n";
            }
        }
    }
    cout << "\n";
    return 0;
};