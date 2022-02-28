#include <cstdio>
#include "probelib.h"

int search(int l,int h){
    if(l==h){
        probe_answer(l);
    }
    else if(probe_check(l,l+((h-l)/2))){
        search(l,l+((h-l)/2));
    }
    else{
        search(l+((h-l)/2)+1,h);
    }
}

int main(){
    int n = probe_init();
    search(0,n-1);
}