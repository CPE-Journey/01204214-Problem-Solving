#include <iostream>
#include <list>
using namespace std;

void printList(list<int> lst){
    for(auto i=lst.begin();i!=lst.end();++i){
        cout << *i << "\n";
    }
}

int main(){
    int m,no,pop_ic;
    char opr,side;
    list<int> ic;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> side >> opr;
        if(opr == 'i'){
            cin >> no;
            if(side == 'r'){
                ic.push_back(no);
            }
            else{
                ic.push_front(no);
            }
        }
        else if(ic.size() > 0){
            if(side == 'r'){
                pop_ic = ic.back();
                ic.pop_back();
                ic.push_front(pop_ic);
            }
            else{
                pop_ic = ic.front();
                ic.pop_front();
                ic.push_back(pop_ic);
            }
        }
    }
    
    printList(ic);

    return 0;
}