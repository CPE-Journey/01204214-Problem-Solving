#include <iostream>
#include <list>
using namespace std;

void printList(list<char> text){
    for(auto i=text.begin();i!=text.end();i++){
        cout << *i;
    }
    cout << "\n";
}

int main(){
    bool enableHome = false;
    string type;
    list<char> display;
    list<char> :: iterator start;

    while(getline(cin,type)){
        display.clear();
        enableHome = false;
        for(int i=0;i<type.length();i++){
            if(type[i]=='['){
                enableHome = true;
                start = display.begin();
            }
            else if(type[i]==']'){
                enableHome = false;
            }
            else if(enableHome){
                display.insert(start,type[i]);
            }
            else{
                display.push_back(type[i]);
            }
        }
    printList(display);
    }
    return 0;
}