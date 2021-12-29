#include <iostream>
#include <vector>
#include <list>
using namespace std;

void printGraph(vector<vector<int>> v){
    for(int i=0;i<v.size();i++){
        cout << i << ": ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
}

string bipartie(){
    int N,M,v1,v2,deq,toggle=0;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<vector<int>> team;
    team.resize(N,vector<int>(2));

    vector<int> visit(N);
    list<int> queue;

    for(int i=0;i<M;i++){
        cin >> v1 >> v2;
        v1--;
        v2--;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    queue.push_back(0);
    visit[0] = 1;
    while(!queue.empty()){
        deq = queue.front();
        // cout << deq << " ";
        queue.pop_front();

        for(int i=0;i<graph[deq].size();i++){
            if(visit[graph[deq][i]]){
                if(team[!toggle][graph[deq][i]]){
                    return "no";
                }
                continue;
            }
            queue.push_back(graph[deq][i]);
            visit[graph[deq][i]] = 1;
            team[toggle][graph[deq][i]] = 1;
        }

        toggle = !toggle;
    }
    return "yes";
}

int main(){
    int N;
    cin >> N;

    for(int i=0;i<N;i++){
        cout << bipartie() << "\n";
    }

    return 0;
}