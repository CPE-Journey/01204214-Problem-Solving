#include <iostream>
#include <vector>
using namespace std;

int virus=0;
vector<int> dna;

int main(){
    int n,m,input,num;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> input;
        dna.push_back(input);
    }

    for(int i=0;i<m;i++){
        cin >> input;
        auto it= dna.begin();
        switch(input){
            case 1:
                virus=0; break;
            case 2:
                virus++;
                if(virus==dna.size())
                    virus=0;
                break;
            case 3:
                cin >> num;
                dna.insert(it+virus,num); 
                virus++;
                break;
            case 4:
                cin >> num;
                dna.insert(it+virus+1,num); 
                break;
        }

    }

    for(int i=0;i<dna.size();i++){
        cout << dna[i] << endl;
     }

}