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
    int n = 10,count = 1,max_value,max_index,prev_max;
    bool isFound;
    int dish[] = {1, 5, 2, 7, 3, 2, 7, 3, 8, 4};
    int done[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(allDone(done,n)){
        max_value = 0;
        max_index = 0;
        prev_max = 999999;
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
                cout << max_value << " ";
            }
        }
    }

    cout << count;
}