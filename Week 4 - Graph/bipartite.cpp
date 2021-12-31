#include <iostream>
#include <vector>
#include <list>
using namespace std;

string bipartie(){
    int N,M,v1,v2,deq,toggle=0;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    vector<vector<int>> team;
    team.resize(2,vector<int>(N));

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
    team[1][0] = 1;
    while(!queue.empty()){
        deq = queue.front();
        queue.pop_front();

        toggle = team[0][deq] ? 0 : 1; // First Time ALways 1
        visit[deq] = 1;

        for(int i=0;i<graph[deq].size();i++){
            if(visit[graph[deq][i]]){
                if(team[toggle][graph[deq][i]]){
                    return "no";
                }
                continue;
            }
            queue.push_back(graph[deq][i]);
            team[!toggle][graph[deq][i]] = 1;
        }
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