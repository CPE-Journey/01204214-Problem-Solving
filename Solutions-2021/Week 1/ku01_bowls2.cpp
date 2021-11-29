#include <iostream>
using namespace std;

bool allDone(int *arr,int n){
    for(int i=0;i<n;i++){
        if(!arr[i]){
            return true;
        }
    }
    return false;
}

int main(){
    int n = 10,count = 0,max_value,max_index,prev_max;
    bool isFound;
    // cin >> n;
    int dish[n] = {1, 5, 2, 7, 3, 2, 7, 3, 8, 4};
    int done[n] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    // for(int i=0;i<n;i++){
        cin >> dish[i];
    //     done[i] = 0;
    // }

    while(allDone(done,n)){
        max_value = 999999;
        max_index = 0;
        prev_max = 0;
        for(int i=0;i<n;i++){
            isFound = false;
            prev_max = max_value;
            max_value = 0;
            max_index = 0;
            for(int j=0;j<n;j++){
                if(dish[j] > max_value && dish[j] < prev_max && !done[j]){
                    isFound = true;
                    max_value = dish[j];
                    max_index = j;
                }
            }
            if(!isFound){
                count++;
                break;
            }
            else{
                done[max_index] = 1;
                // cout << max_value << " ";
            }
        }
    }

    cout << count;
}