#include <iostream>
using namespace std;

int distance(int x,int y){
    return x*x + y*y;
}

int main(){
    int radius[] = {2,4,6,8,10};
    int score[] =  {5,4,3,2,1};
    int sum = 0,n,x,y,dart;

    cin >> n;
    for(int j=0;j<n;j++){
        cin >> x >> y;
        dart = distance(x,y);
        for(int i=0;i<5;i++){
            if(dart <= radius[i]*radius[i]){
                sum += score[i];
                break;
            }
        }
    }
    cout << sum;
}