#include <iostream>
using namespace std;

int year,cancel=0,input;
char university[] = {'K','C'};
int main(){
    cin >> year;
    while(true){
        cin >> input;
        if(input == 0)
            break;
        cancel++;
    }
    cout << university[(year-cancel)%2] << "\n";
    return 0;
}