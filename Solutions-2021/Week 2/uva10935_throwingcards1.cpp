#include <iostream>
#include <list>
#include <vector>
using namespace std;

void printList(list<int> lst){
    for(auto i = lst.begin();i!=lst.end();++i){
        cout << *i << " ";
    }
    cout << "\n";
}

void throwingCard(int n){
    int insert_card;
    list<int> deck;
    vector<int> discarded;
    for(int i=1;i<=n;i++){
        deck.push_back(i);
    }
    while(deck.size() > 1){
        discarded.push_back(deck.front());
        deck.pop_front();
        deck.push_back(deck.front());
        deck.pop_front();
    }
    cout << "Discarded cards:";
    if(n!=1){
        cout << " ";
    }
    for(int i=0;i<discarded.size();i++){
        cout << discarded[i];
        if(i != discarded.size()-1){
            cout << ", ";
        }
    }
    cout << "\n" << "Remaining card: " << deck.front() << "\n";
}

int main(){
    int N;
    while(true){
        cin >> N;
        if(N == 0){
            break;
        }
        throwingCard(N);
    }
    return 0;
}