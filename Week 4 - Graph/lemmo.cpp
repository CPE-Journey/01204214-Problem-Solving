#include <iostream>
#include <vector>
using namespace std;

int W,H,count=0,digCount=0,max_digCount=0;
char input;
vector<vector<char>> maze;

void printMaze(vector<vector<char>> m){
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m[i].size();j++){
            cout << m[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

int walk(int start,int initDir){
    int j=start,i=0,direction=initDir; // 0 = Left | 1 = Right

    // while(maze[i][j] == '.') i++;

    while(maze[i][j] != '@' && maze[i][j] != '$'){
        while(maze[i][j] == '.') i++;
        if(!(maze[i][j] != '@' && maze[i][j] != '$'))continue;
        // cout << i << " " << j << "\n";
        if(j==0) direction = 1;
        else if(j==maze[0].size()-1) direction = 0;

        if(direction) j++;
        else j--;

        // while(maze[i][j] == '.') i++;
        // cout << maze[i][j] << " ";
    }
    return maze[i][j] == '$' ? 1 : 0;
}

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    cin >> W >> H;
    maze.resize(H);
    
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> input;
            maze[i].push_back(input);
        }
    }

    for(int i=0;i<W;i++){
        count += walk(i,0);
        count += walk(i,1);
    }

    for(int i=0;i<H-1;i++){
        for(int j=0;j<W;j++){
            if(maze[i][j] != '#') continue;
            maze[i][j] = '.';
            // printMaze(maze);
            digCount = 0;
            for(int k=0;k<W;k++){
                digCount += walk(k,0);
                digCount += walk(k,1);
            }
            max_digCount = max(max_digCount,digCount);
            maze[i][j] = '#';
        }
    }

    cout << count << " " << max_digCount;
    return 0;
}