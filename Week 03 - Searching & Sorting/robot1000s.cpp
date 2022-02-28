#include <iostream>
#include <vector>
using namespace std;

int k = 2;
string command = "NE";
vector<int> count = {0,0,0,0};
vector<int> lowPriority; // Vertical = 0
vector<int> highPriority; // Horizontal = 1

int absoluteZero(int value){
    return value < 0 ? 0 : value;
}

void deleteMin(int a,int b){
    if(count[a]<count[b] && count[a] != 0){
        count[a] = absoluteZero(count[a]-1);
    }
    else{
        count[b] = absoluteZero(count[b]-1);
    }
}

void printVector(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout << i << ": " << v[i] << "  ";
    }
    cout << "\n";
}

int main(){
    for(int i=0;i<command.length();i++){
        switch(command[i]){
            case 'N': count[0] += 1; break;
            case 'E': count[1] += 1; break;
            case 'S': count[2] += 1; break;
            case 'W': count[3] += 1; break;
        }
    }

    if(count[0] > count[2]){
        lowPriority.push_back(0);
        highPriority.push_back(2);
    }
    else{
        lowPriority.push_back(2);
        highPriority.push_back(0);
    }

    if(count[1] > count[3]){
        lowPriority.push_back(1);
        highPriority.push_back(3);
    }
    else{
        lowPriority.push_back(3);
        highPriority.push_back(1);
    }

    // printVector(count);
    // cout << "MAX PAIR >> ";
    // printVector(lowPriority);
    // cout << "MIN PAIR >> ";
    // printVector(highPriority);

    
    for(int i=0;i<k;i++){
        if(count[highPriority[0]] > 0){
            count[highPriority[0]] -= 1;
            // deleteMin(lowPriority[0],highPriority[0]);
        }
        else if(count[highPriority[1]] > 0){
            count[highPriority[1]] -= 1;
            // deleteMin(lowPriority[1],highPriority[1]);
        }
        else{
            highPriority[0] = lowPriority[0];
            highPriority[1] = lowPriority[1];
            i--;
            // cout << "MAX PAIR >> ";
    // printVector(lowPriority);
    // cout << "MIN PAIR >> ";
    // printVector(highPriority);
        }
    }

    // printVector(count);
    cout << (count[lowPriority[0]]+count[lowPriority[1]]-count[highPriority[0]]-count[highPriority[1]])*2;
}