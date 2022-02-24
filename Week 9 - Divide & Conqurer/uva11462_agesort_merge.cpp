#include <iostream>
#include <vector>
using namespace std;

vector<int> age = {3,4,2,1,5};

void merge(int s,int t){
    int start=s+0,mid=s+(t-s)/2;

    while(start <= s+(t-s)/2 && mid <= t){
        if(age[start] < age[mid]){
            start++;
        }
        else{
            swap(age[start],age[mid]);
            mid++;
        }
    }
}

void mergeSort(int s,int t){
    printf("%d %d\n",s,t);
    if(s == t){
        return;
    }
    mergeSort(s,s+(t-s)/2);
    mergeSort(s+(t-s)/2+1,t);
    merge(s,t);
}

int main(){
    mergeSort(0,4);
}