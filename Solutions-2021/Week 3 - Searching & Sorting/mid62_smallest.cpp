#include <iostream>
#include <vector>
using namespace std;

int min(int a,int b){
    return a > b ? b : a;
}

int search(vector<long int> v,int h,int current){
    if(v[current] > h){
        return search(v,h,current+(current/2));
    }
    else{
        return search(v,h,current/2);
    }
}

int main(){
    int N,Q,j,prev_j=0,T,k;
    long int height,min_height = 1000000001;
    vector<long int> row;
    vector<long int> minHeight;
    vector<vector<long int>> minHeightME; // {index,value}

    cin >> N >> Q;
    for(int i=0;i<N;i++){
        cin >> height;
        min_height = min(min_height,height);
        minHeight.push_back(min_height); 
        
        if(i != 0 && minHeight[i] != minHeight[i-1]){
            minHeightME.push_back({i,minHeight[i-1]});
            if(i == N-1){
                minHeightME.push_back({N,min_height});
            }
        }
    }

    

    for(int i=0;i<minHeightME.size();i++){
        cout << minHeightME[i][0] << " " << minHeightME[i][1] << "\n";
    }

    for(int i=0;i<Q;i++){
        cin >> T >> j;

        // Question #1
        if(T == 1){
            cout << minHeight[j-1] << "\n";
        }

        // Question #2
        else{
            for(int a=0;a<minHeightME.size();a++){
                if(minHeightME[a][1] < j){
                    cout << minHeightME[a-1][0] << "\n";
                    break;
                }
            }
            
        }
    }

    return 0;
}