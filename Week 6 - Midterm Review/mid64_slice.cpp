#include <iostream>
#include <vector>
using namespace std;

int N,h,max_height=0,start;
vector<int> model,block,used;

int main(){
    cin >> N;
    block.resize(N);

    for(int i=0;i<N;i++){
        cin >> h;
        model.push_back(h);
        max_height = max_height > h ? max_height : h;
    }

    for(int i=1;i<=max_height;i++){
        start = -1;
        for(int j=0;j<N;j++){
            if(model[j] < i){
                if(block[j-start-1] == 0){
                    used.push_back(j-start-1);
                }
                block[j-start-1] += 1;
                start = j;
            }
        }
        block[N-start-1] += 1;
    }
    return 0;
}