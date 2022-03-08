#include <iostream>
#include <vector>
using namespace std;

int N,S,isFound,max_behind=-1000001,prevNum;
vector<int> longest,behind,input,answer;

int Max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> S;
        isFound = 0;
        for(int j=0;j<longest.size();j++){
            if(longest[j] >= S){
                longest[j] = S;
                isFound = 1;
                if(j==0){
                    behind.push_back(-1000001);
                }
                else{
                    prevNum = longest[j-1];
                    behind.push_back(prevNum);
                    max_behind = Max(max_behind,prevNum);
                }
                break;
            }
        }
        if(!isFound){
            longest.push_back(S);
            if(i==0){
                behind.push_back(-1000001);
            }
            else{
                prevNum = longest[longest.size()-2];
                behind.push_back(prevNum);
                max_behind = Max(max_behind,prevNum);
            }
        }
        input.push_back(S);
    }
    for(int i=N-1;i>=0;i--){
        if(input[i] == longest[longest.size()-1]){
            max_behind = behind[i];
            break;
        }
    }
    // max_behind = longest[longest.size()-1];
    cout << longest.size() << "\n";

    for(int i=N-1;i>=0;i--){
        // cout << i << " " << behind[i] << "\n";
        // printf("%d %d MAX-Behind: %d\n",i,behind[i],max_behind);
        if(behind[i] == max_behind){
            answer.push_back(input[i]);
            for(int j=0;j<N;j++){
                if(input[j] == max_behind){
                    max_behind = behind[j];
                    if(behind[j] == -1000001){
                        answer.push_back(input[j]);
                    }
                    break;
                }
            }
            if(max_behind == -1000001){
                break;
            }
        }
    }
    for(int i=0;i<longest.size();i++){
        // cout << longest[i] << " ";
    }
    // cout << "\n";
    for(int i=answer.size()-1;i>=0;i--){
        cout << answer[i] << " ";
    }
    // cout << "\n";
    for(int i=0;i<N;i++){
        // cout << behind[i] << " ";
    }
}