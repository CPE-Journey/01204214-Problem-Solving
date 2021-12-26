#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,Q,input;
    long long int min_height = 1000000001;
    vector<long long int> minValue;
    vector<long long int> minIndex;

    cin >> N >> Q;

    for(int i=0;i<N;i++){

        cin >> input;
        
        if(input < min_height){
            if(i != 0){
                minValue.push_back(min_height);
                minIndex.push_back(i);
            }
            if(i == N-1){
                minValue.push_back(input);
                minIndex.push_back(i+1);
            }
            min_height = input;
        }
    }

    for(int i=0;i<minValue.size();i++){
        cout << minValue[i] << " " << minIndex[i] << "\n";
    }

}


// int min(int a,int b){
//     return a > b ? b : a;
// }

// int positive(int n){
//     return n < 0 ? 0 : n;
// }

// int search(vector<long long int> v,int h,int current){
//     if(v[current] > h){
//         return search(v,h,current+(current/2));
//     }
//     else{
//         return search(v,h,current/2);
//     }
// }

// int main(){
//     int N,Q,j,prev_j=0,T,k;
//     long long int height,min_height = 1000 000 001;
//     bool isFound;
//     vector<long long int> row;
//     vector<long long int> minHeight;
//     vector<vector<long long int>> minHeightME; // {index,value}
//     vector<long long int> minValue;

//     cin >> N >> Q;
//     for(int i=0;i<N;i++){
//         cin >> height;
//         min_height = min(min_height,height);
//         minHeight.push_back(min_height); 
        
//         if(i != 0 && minHeight[i] != minHeight[i-1]){
//             minHeightME.push_back({i,minHeight[i-1]});
//             minValue.push_back(minHeight[i-1]);
//             if(i == N-1){
//                 minHeightME.push_back({N,min_height});
//                 minValue.push_back(min_height);
//             }
//         }
//     }

//     for(int i=0;i<Q;i++){
//         cin >> T >> j;

//         // Question #1
//         if(T == 1){
//             cout << minHeight[j-1] << "\n";
//         }

//         // Question #2
//         else{
//             cout << lower_bound(minValue.begin(),minValue.end(),j)-minValue.begin() << "\n";
//             // isFound = false;
//             // for(int a=0;a<minHeightME.size();a++){
//             //     if(minHeightME[a][1] < j){
//             //         isFound = true;
//             //         if(a == 0){
//             //             cout << 0 << "\n";
//             //         }
//             //         else{
//             //             cout << minHeightME[a-1][0] << "\n";
//             //         }
//             //         break;
//             //     }
//             // }
//             // if(!isFound){
//             //     cout << minHeightME[minHeightME.size()-1][0] << "\n";
//             // }
//         }
//     }

//     return 0;
// }