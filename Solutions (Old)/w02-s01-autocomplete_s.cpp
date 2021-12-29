#include <iostream>
using namespace std;

bool alreadyIn(string word,string *prefix,int n){
    bool isRejected;
    for(int i=0;i<n;i++){
        if(word.length() != prefix[i].length()){
            continue;
        }
        isRejected = false;
        for(int j=0;j<prefix[i].length();j++){
            if(prefix[i][j] != word[j]){
                isRejected = true;
                break;
            }
        }
        if(!isRejected){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    string text[n];
    string prefix[n];

    for(int i=0;i<n;i++){
        cin >> text[i];
    }

    for(int i=0;i<n;i++){
        prefix[i] = "";
    }

    int sum_len = 0;
    string typing;
    for(int i=0;i<n;i++){
        typing = "\0";
        int j = 0;
        while(j == 0 || alreadyIn(typing,prefix,n) || alreadyIn(typing,text,i)){
            typing += text[i][j];
            j++;
        }
        typing += "\0";
        prefix[i] = typing;
        sum_len += typing.length();
    }
    cout << sum_len;
    return 0;
}