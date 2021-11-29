#include <iostream>
using namespace std;

int main(){
    string input;
    cin >> input;
    int x=0,y=0;
    for(int i=0;i<input.length();i++){
        switch(input[i]){
            case 'W':
                x--;
                break;

            case 'E':
                x++;
                break;

            case 'S':
                y--;
                break;

            case 'N':
                y++;
                break;

            case 'Z':
                x=0;
                y=0;
                break;
        }
    }
    cout << x << " " << y;
}