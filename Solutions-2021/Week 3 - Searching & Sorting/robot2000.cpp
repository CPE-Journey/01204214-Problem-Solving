#include <iostream>
#include <vector>
using namespace std;

char Direction[] = {'N','E','S','W'};

int InverseDirection(char d){
    for(int i=0;i<4;i++){
        if(Direction[i]==d){
            return i;
        }
    }
    return -1;
}
// string transform(string v){
//     int dir = 0;
//     //  0
//     //3   1
//     //  2
// }

int main(){
    int dir = 0,distance;
    string v1000 = "NENENENE",v2000 = "";
    
    for(int i=0;i<v1000.length();i++){
        cout << v1000[i] << "->";
        if(v1000[i] == 'Z'){
            dir = 0;
            cout << "RTN\n";
            v2000 += 'Z';
        }
        else if(Direction[dir] == v1000[i]){
            cout << "SME\n";
            v2000 += 'F';
        }
        else{
            cout << "CHN";
            distance = abs(dir-InverseDirection(v1000[i]));
            dir = (dir+distance)%4;
            cout << " Distance " << distance << " " << Direction[dir] << "\n";
            for(int j=0;j<distance;j++){
                v2000 += 'R';
            }
            v2000 += 'F';
        }
        cout << "Result: " << v2000 << "\n";
    }
}