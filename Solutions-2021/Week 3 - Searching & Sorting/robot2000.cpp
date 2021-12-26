#include <iostream>
#include <vector>
using namespace std;

char Direction[] = {'N','E','S','W'};

int main(){
    int dir = 0,distance;
    string v1000,v2000 = "";
    
    cin >> v1000;

    for(int i=0;i<v1000.length();i++){
        if(v1000[i] == 'Z'){
            dir = 0;
            v2000 += 'Z';
        }
        else if(Direction[dir] == v1000[i]){
            v2000 += 'F';
        }
        else{
            while(Direction[dir] != v1000[i]){
                v2000 += 'R';
                dir = (dir+1)%4;
            }
            v2000 += 'F';
        }
    }
    cout << v2000;
    return 0;
}