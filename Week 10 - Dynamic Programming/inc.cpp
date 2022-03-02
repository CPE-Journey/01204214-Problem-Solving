#include <iostream>
#include <vector>
using namespace std;

int N,input,isFound;
vector<int> longest,behind;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> input;
        isFound = 0;
        for(int j=0;j<longest.size();j++){
            if(longest[j] >= input){
                longest[j] = input;
                isFound = 1;

                if(j==0){
                    behind.push_back(-1000001);
                }
                break;
            }
        }
        if(!isFound){
            longest.push_back(input);
            behind.push_back(longest.size()-2);
        }
    }   
    cout << longest.size() << "\n";
    for(int i=0;i<longest.size();i++){
        // cout << longest[i] << " ";
    }
    for(int i=0;i<N;i++){
        cout << behind[i] << " ";
    }
}