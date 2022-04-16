#include <iostream>
#include <vector>
using namespace std;

int N,M,number,score;
vector<int> maxScore,count;

void check(){
    cout << "=======\n";
    for(int i=1;i<=N;i++){
        printf("%d %d\n",maxScore[i],count[i]);
    }
    cout << "=======\n";
}

int main(){
    cin >> N >> M;
    maxScore.resize(N+1);
    count.resize(N+1);

    for(int i=0;i<M;i++){
        cin >> number >> score;
        if(count[number] >= 5){
            maxScore[number] = 0;
        }
        else if(score > maxScore[number]){
            maxScore[number] = score;
        }
        count[number] += 1;
    }

    int sum = 0;
    for(int i=1;i<=N;i++){
        sum += maxScore[i];
        // cout << maxScore[i] << "\n";
    }
    cout << sum << "\n";
}