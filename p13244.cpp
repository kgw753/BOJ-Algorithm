#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int T, N, E, a, b, cnt;
vector<vector<int>> MAP(MAX, vector<int>());
vector<int> visited(MAX, 0);
vector<string> answer;

void dfs(int idx){
    visited[idx] = 1;
    for(int i = 0; i < MAP[idx].size(); i++){
        if(visited[MAP[idx][i]]) continue;
        dfs(MAP[idx][i]);
    }
}

int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> E;
        fill(visited.begin(), visited.end(), 0);
        for(int j = 0; j < N; j++) MAP[j].clear();
        for(int j = 0; j < E; j++){
            cin >> a >> b;
            MAP[a].push_back(b);
            MAP[b].push_back(a);
        }
        cnt = 0;
        for(int i = 1; i <= N; i++){
            if(visited[i] == 0){
                dfs(i);
                cnt++;
            }
        }
        if(cnt == 1 && N - 1 == E) answer.push_back("tree");
        else answer.push_back("graph");
    }
    for(int i = 0; i < T; i++) cout << answer[i] << "\n";
}