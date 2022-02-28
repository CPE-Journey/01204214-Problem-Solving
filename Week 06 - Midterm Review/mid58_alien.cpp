#include <iostream>
using namespace std;

int N,a,b,R,x,y,count = 0;

int distance(int x1,int y1,int x2,int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main(){
    cin >> N >> a >> b >> R;
    for(int i=0;i<N;i++){
        cin >> x >> y;
        if(distance(x,y,a,b) <= R*R){
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}