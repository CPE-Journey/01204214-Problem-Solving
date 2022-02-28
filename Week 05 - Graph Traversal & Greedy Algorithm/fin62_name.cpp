#include <iostream>
#include <vector>
using namespace std;

int current = 0,count = 0,len;
string name,message;

int main(){
    cin >> name >> message;
    len = name.length();
    for(int i=0;i<message.length();i++){
        if(message[i] == name[current]){
            count += (current+1)/len;
            current = (current+1)%len;
        }
    }
    cout << count;
    return 0;
}