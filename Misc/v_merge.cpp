#include<iostream>
#include<vector>
using namespace std;

vector<int> age;

int N=1;

void print(){
    for(int i=0;i<N;i++){
        printf("%d ",age[i]);
    }
    printf("\n");
}

void merge(int l,int m,int r){
    int i,j,k;//i,j=index 
    int nl = m-l+1; // ความยาวของ arr แรก
    int nr = r-m; //ความยาว arr หลัง
    int L[nl] ,R[nr];
    //copy data from age to L ,R
    // printf("L[i]: ");
    for(int i=0;i<nl;i++){
        L[i]=age[l+i];
        // printf("%d ",L[i]);
    }
    // printf("\nR[i]: ");
    for(int i=0;i<nr;i++){
        R[i]=age[m+i+1];
        printf("%d ",R[i]);
    }
    // printf("\n");

    i=0; j=0; k=l;
    //merge
    while(i<nl||j<nr){
        if(L[i] <= R[j]){
            age[k] = L[i];
            i++;
        }else{
            age[k] = R[j];
            j++;
        }
        k++;
        // print();
    }
}

void merge_sort(int l,int r){
    int m;
    if(l<r){
        m = l+(r-l)/2;
        merge_sort(l,m);
        merge_sort(m+1,r);
        merge(l,m,r);
    }
}

int main(){
    int old;
    while(N!=0){
        scanf("%d",&N);
        if(N==0){
            break;
        }
        age.resize(N);
        for(int i=0;i<N;i++){
            scanf("%d",&old);
            age[i]=old;
        }
        merge_sort(0,N-1);
        // printf("main\n");
        print();
        
    }
    return 0;
}