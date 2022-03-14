#include <iostream>
#include <vector>
using namespace std;

long long int N,input,count=0;
vector<long long int> number;

long long int merge(long long int l,long long int m,long long int r){
    long long int nL = m-l+1,nR = r-m,mid = (r-l)/2;
    long long int left[nL],right[nR];

    for(long long int i=0;i<nL;i++){
        left[i] = number[l+i];
    }
    for(long long int i=0;i<nR;i++){
        right[i] = number[m+i+1];
    }

    long long int i=0,j=0,k=l,sub_count = 0;
    while(i < nL && j < nR){
        if(left[i] <= right[j]){
            
            number[k++] = left[i++];
        }
        else{
            sub_count += mid-i+1;
            number[k++] = right[j++];
        }
        
    }
    while(i < nL){
        number[k++] = left[i++];
    }
    while(j < nR){
        number[k++] = right[j++];
    }
    return sub_count;
}

long long int mergeSort(long long int l,long long int r){
    if(l >= r){
        return 0;
    }
    long long int mid = l + (r-l)/2;
    long long int l_res = mergeSort(l,mid);
    long long int r_res = mergeSort(mid+1,r);
    return l_res + r_res + merge(l,mid,r);
}

int main(){
    cin >> N;
    for(long long int i=0;i<N;i++){
        cin >> input;
        number.push_back(input);
    }
    cout << mergeSort(0,N-1);
    return 0;
} 