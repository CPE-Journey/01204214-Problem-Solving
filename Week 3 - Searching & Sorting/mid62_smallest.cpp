#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int N,Q,question,T,height_index,answer;
long long int min_height = 1000000001,input,shortest,tallest,tmp;
vector<int> order;
vector<long long int> height;

int main(){
    cin >> N >> Q;

    for(int i=0;i<N;i++){
        cin >> input;
        if(input < min_height){
            min_height = input;
            order.push_back(i+1);
            height.push_back(min_height);
        }
    }

    shortest = height[height.size()-1];
    tallest = height[0];

    order.push_back(N+1);
    height.push_back(0);
    
    // reverse(height.begin(),height.end());

    for(int i=0;i<height.size()/2;i++){
        tmp = height[i];
        height[i] = height[height.size()-1-i];
        height[height.size()-1-i] = tmp;
    }

    // sort(height.begin(),height.end());
    // for(int i=0;i<N;i++){
    //     cout << height[i] << " ";
    // }
    // cout << height.size();
    // cout << "\n";

    for(int i=0;i<Q;i++){
        cin >> question >> T;
        if(question==1){
            height_index = upper_bound(order.begin(),order.end(),T)-order.begin()-1;
            cout << height[height.size()-1-height_index];
        }
        else{
            if(T < shortest){
                cout /* << "Cond 1 : " */ << N;
            }
            else if(T > tallest){
                cout /* << "Cond 2 : " */ << 0;
            }
            else{
                height_index = lower_bound(height.begin(),height.end(),T)-height.begin()-1;
                answer = order[order.size()-1-height_index];
                cout << answer-1;
            }
        }
        cout << "\n";
    }
    return 0;
}


// #include <iostream>
// #include <vector>
// using namespace std;

// int min(int a,int b){
//     return a > b ? b : a;
// }

// int search(vector<long int> v,int h,int current){
//     if(v[current] > h){
//         return search(v,h,current+(current/2));
//     }
//     else{
//         return search(v,h,current/2);
//     }
// }

// int main(){
//     int N,Q,j,prev_j=0,T,k;
//     long int height,min_height = 1000000001;
//     bool isFound;
//     vector<long int> row;
//     vector<long int> minHeight;
//     vector<vector<long int>> minHeightME; // {index,value}

//     cin >> N >> Q;
//     for(int i=0;i<N;i++){
//         cin >> height;
//         min_height = min(min_height,height);
//         minHeight.push_back(min_height); 
        
//         if(i != 0 && minHeight[i] != minHeight[i-1]){
//             minHeightME.push_back({i,minHeight[i-1]});
//             if(i == N-1){
//                 minHeightME.push_back({N,min_height});
//             }
//         }
//     }

    

//     for(int i=0;i<minHeightME.size();i++){
//         cout << minHeightME[i][0] << " " << minHeightME[i][1] << "\n";
//     }

//     for(int i=0;i<Q;i++){
//         cin >> T >> j;

//         // Question #1
//         if(T == 1){ 
//             cout << minHeight[j-1] << "\n";
//         }

//         // Question #2
//         else{
//             isFound = false;
//             for(int a=0;a<minHeightME.size();a++){
//                 if(minHeightME[a][1] < j){
//                     cout << minHeightME[a-1][0] << "\n";
//                     isFound = true;
//                     break;
//                 }
//             }
//             if(!isFound){
//                 cout << /* minHeightME[a][0] */ minHeightME[minHeightME.size()-1][0] << "\n";
//             }
//         }
//     }

//     return 0;
// }