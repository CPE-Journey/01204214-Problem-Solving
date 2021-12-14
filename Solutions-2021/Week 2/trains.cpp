#include <iostream>
#include <list>
using namespace std;

int main(){
    int t,v1,v2;
    char opr;
    list<int> train[100001];
    
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> opr >> v1 >> v2;
        if(opr == 'N'){
            train[v2].push_back(v1);
        }
        else{
            train[v2].splice(train[v2].end(),train[v1]);
        }
    }

    for(int i=0;i<100001;i++){
        for(auto j = train[i].begin();j!=train[i].end();++j){
            cout << *j << "\n";
        }
    }

    return 0;
}