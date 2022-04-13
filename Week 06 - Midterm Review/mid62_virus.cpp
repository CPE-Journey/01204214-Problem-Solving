#include <iostream>
#include <list>
using namespace std;

int N,M,current=0,command,input;
list<int> virus;

int main(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        cin >> input;
        virus.push_back(input);
    }

    for(int i=0;i<M;i++){
        cin >> command;
        auto pos = virus.begin();
        
        switch(command){
            case 1:
                current = 0;
                break;
            case 2:
                current = (current+1)%N;
                break;
            case 3:
                cin >> input;
                if(current-1 < 0){
                    virus.push_front(input);
                }
                else{
                    advance(pos,current);
                    virus.insert(pos,input);
                }
                
                current += 1;
                N += 1;
                break;
            case 4:
                cin >> input;
                advance(pos,current+1);
                virus.insert(pos,input);
                N += 1;
                break;
        }
        // printf("CURRENT: %d | ",current);
        // for(auto i:virus){
        //     cout << i << " ";
        // }
        // cout << "\n";
    }
    
    for(auto i:virus){
        cout << i << "\n";
    }
}