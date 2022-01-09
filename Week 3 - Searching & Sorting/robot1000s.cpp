#include <iostream>
#include <vector>
using namespace std;

string input;
int x=0,y=0,k;
bool toggle = true;

vector<int> counter(4);

//  0
// 3 1
//  2

void walk(char direction){
    switch(direction){
        case 'N': y++; return;
        case 'E': x++; return;
        case 'S': y--; return;
        case 'W': x--; return;
    }
}

void furthest(){
    while(k > 0){
        if(toggle){
            if(x > 0) x++;
            else if(x < 0) x--;
        }
        else{
            if(y > 0) y++;
            else if(x < 0) y--;
        }
        k--;
        toggle = !toggle;
    }
}

void deleteMin(bool d){
    if(d){
        if(counter[0] > counter[2]){
            counter[2]--;
        }
        else{
            counter[0]--;
        }
    }
    else{
        if(counter[1] > counter[3]){
            counter[3]--;
        }
        else{
            counter[1]--;
        }
    }
}

void printCount(){
    printf("N: %d E: %d S: %d W: %d\n",counter[0],counter[1],counter[2],counter[3]);
}

int main(){
    cin >> input >> k;
    // printCount();
    for(int i=0;i<input.length();i++){
        switch(input[i]){
            case 'N': counter[0] += 1; break;
            case 'E': counter[1] += 1; break;
            case 'S': counter[2] += 1; break;
            case 'W': counter[3] += 1; break;
        }
        // printCount();
    }
    // printCount();
    for(int i=0;i<k;i++){
        deleteMin(toggle);
        toggle = !toggle;
    }
    printCount();
    // cout << (abs(x)+abs(y))*2;
}