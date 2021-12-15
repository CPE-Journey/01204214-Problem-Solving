#include <iostream>
#include <list>
using namespace std;

int main() {
    int N,coach,current;
    list<int> station;
    cin >> N;

    current = 1;
    for(int i=1;i<=N;i++){
        cin >> coach;
        if(!station.empty() && station.back()==coach){
            cout << "Pop" << coach << "\n";
            station.pop_back();
        }
        else{
            for(int j=current;j<=N;j++){
                if(current == coach){
                    break;
                }
                cout << "Push " << current << "\n";
                station.push_back(current++);
            }
        }
    }
    if(!station.empty()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
};