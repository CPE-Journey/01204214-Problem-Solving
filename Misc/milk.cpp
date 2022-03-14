#include <iostream>
#include <vector>
using namespace std;

vector<int> Parent;
vector<int> Count;
vector<string> ans;

int find_Parent(int milk) {
    if (Parent[milk] == milk) {
        return milk;
    }
    return find_Parent(Parent[milk]);
}

void Union(int parent_X,int parent_Y) {
    if (Count[parent_X] >= Count[parent_Y]) {
        Parent[parent_Y] = parent_X;
        Count[parent_X] += Count[parent_Y];
    }else {
        Parent[parent_X] = parent_Y;
        Count[parent_Y] += Count[parent_X];
    } 
}

int main() {
    int N,Q,i;
    int X,Y,parent_X,parent_Y;
    char question;
    cin >> N >> Q;
    for (i=0;i<N;i++) {
        Parent.push_back(i);
        Count.push_back(1);
    }
    for (i=0;i<Q;i++) {
        cin >> question;
        cin >> X >> Y;
        switch (question) {
        case 'c':
            parent_X = find_Parent(X);
            parent_Y = find_Parent(Y);
            if (parent_X != parent_Y) {
                Union(parent_X,parent_Y);
            }
            //cout << "X: " << Parent[X] << endl;
            //cout << "Y: " << Parent[Y] << endl;
            break;
        case 'q':
            parent_X = find_Parent(X);
            parent_Y = find_Parent(Y);
            if (parent_X != parent_Y) {
                //cout << "no" << endl;
                ans.push_back("no");
            }else {
                //cout << "yes" << endl;
                ans.push_back("yes");
            }
            break;
        }
    }
    for (auto tmp = ans.begin();tmp != ans.end();tmp++) {
        cout << *tmp << endl;
    }
    return 0;
}