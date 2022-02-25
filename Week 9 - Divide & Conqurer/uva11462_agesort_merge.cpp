#include <iostream>
#include <vector>
using namespace std;

<<<<<<< HEAD
int N,input;
vector<int> age;

void printAge(){
    for(int i=0;i<age.size();i++){
            cout << age[i] << " ";
        }
    cout << "\n";
}

void merge(int l,int m,int r){
    int len_l = m-l+1,len_r = r-m;
    vector<int> left_age,right_age;
    for(int i=0;i<len_l;i++){
        left_age.push_back(age[l+i]);
    }
    for(int i=0;i<len_r;i++){
        right_age.push_back(age[m+1+i]);
    }

    int k = l,i=0,j=0;
    while(i < len_l && j < len_r){
        if(left_age[i] < right_age[j]){
            age[k] = left_age[i];
            i++;
        }
        else{
            age[k] = right_age[j];
            j++;
        }
        k++;
    }
    while(i<len_l){
        age[k] = left_age[i];
        i++;k++;
    }
    while(j<len_r){
        age[k] = right_age[j];
        j++;k++;
    }
    printAge();
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
        mergeSort(0,N);
        printAge();
        age.clear();
    }
    return 0;
=======
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
>>>>>>> f37615646f994da39f4f7457b9f7e6c109361dde
}