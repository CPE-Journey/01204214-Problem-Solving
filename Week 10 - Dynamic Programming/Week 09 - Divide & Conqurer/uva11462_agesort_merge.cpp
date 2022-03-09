#include <iostream>
#include <vector>
using namespace std;

int N,input;
vector<int> age;

void printAge(){
    for(int i=0;i<age.size();i++){
            cout << age[i];
            if(i != age.size()-1)
                cout << " ";
        }
    cout << "\n";
}

void merge(int l,int m,int r){
    int nL = m-l+1,nR = r-m;
    int left[nL],right[nR];

    for(int i=0;i<nL;i++){
        left[i] = age[l+i];
    }
    for(int i=0;i<nR;i++){
        right[i] = age[m+i+1];
    }

    int i=0,j=0,k=l;
    while(i < nL && j < nR){
        age[k++] = (left[i] <= right[j]) ? left[i++] : right[j++];
    }
    while(i < nL){
        age[k++] = left[i++];
    }
    while(j < nR){
        age[k++] = right[j++];
    }
}

void mergeSort(int l,int r){
    if(l >= r){
        return;
    }
    int mid = l + (r-l)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,mid,r);
}

int main(){
    while(true){
        cin >> N;
        if(!N) break;
        for(int i=0;i<N;i++){
            cin >> input;
            age.push_back(input);
        }
        mergeSort(0,N-1);
        printAge();
        age.clear();
    }
    return 0;
}