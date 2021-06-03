#include<bits/stdc++.h>
using namespace std;

vector<bool> visited;
int answer = -1;

void dfs(vector<vector<int>> map, int src, int dest, int depth){
    
    for(int i = 0; i < map[src].size(); i++){
        if(visited[map[src][i]]) continue;
        if(map[src][i] == dest){
            answer = depth + 1;
            return;
        }

        visited[map[src][i]] = true;
        dfs(map, map[src][i], dest, depth + 1);
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<int>> map(N + 1, vector<int>());

    for(int i = 0; i < N + 1; i++) visited.push_back(false);

    int src, dest, r;

    cin >> src >> dest;
    cin >> r;

    for(int i = 0; i < r; i++){
        int x, y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }

    dfs(map, src, dest, 0);
    
    cout << answer << "\n";
}