#include <iostream>
#include <vector>
using namespace std;

int N,input,maxNum,maxSeq=0,last=0;
vector<int> sequence,previous,optimal,answer;

int Max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> N;
    previous.resize(N);
    optimal.resize(N);
    for(int i=0;i<N;i++){
        cin >> input;
        sequence.push_back(input);
    }
    for(int i=0;i<N;i++){
        maxNum = 0;
        for(int j=0;j<i;j++){
            if(sequence[j] < sequence[i] && optimal[j] >= maxNum){
                previous[i] = j;
                maxNum = optimal[j];
            }
        }
        optimal[i] = maxNum + 1;
    }
    for(int i=0;i<N;i++){
        if(optimal[i] > maxSeq){
            maxSeq = optimal[i];
            last = i;
        }
    }
    int i=0,count=maxSeq;
    while(count > 0){
        answer.push_back(sequence[last]);
        last = previous[last];
        count--;
    }
    cout << maxSeq << "\n";
    for(int i=maxSeq-1;i>=0;i--){
        cout << answer[i] << " ";
    }
    cout << "\n";
}