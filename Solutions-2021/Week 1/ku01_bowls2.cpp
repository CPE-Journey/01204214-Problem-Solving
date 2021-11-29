#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,count = 1,max_value,max_index,prev_max;
    cin >> n;
    int remaining = n;
    bool isFound;
    int dish[n]; // = {1, 5, 2, 7, 3, 2, 7, 3, 8, 4};
    int done[n]; // = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for(int i=0;i<n;i++){
        cin >> dish[i];
        done[i] = 0;
    }
    max_value = 999;
    max_index = 0;
    prev_max = 0;
    while(remaining > 0){
        isFound = false;
        prev_max = max_value;
        max_value = 0;
        for(int i=0;i<n;i++){
            if(dish[i] > max_value && dish[i] < prev_max && !done[i]){
                isFound = true;
                max_index = i;
                max_value = dish[i];
            }
        }
        if(isFound){
            done[max_index] = 1;
            remaining--;
            // cout << max_value << " ";
        }
        else{
            count++;
            max_value = 999;
            prev_max = 0;
        }
    }

    cout << count;
}