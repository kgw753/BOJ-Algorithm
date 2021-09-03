#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, M, a, b, visited[MAX], answer[MAX];
vector<vector<int>> MAP(MAX, vector<int>());
int dfs(int idx){
    visited[idx] = 1;
    int ret = 1;
    for(int nxt : MAP[idx]){
        if(visited[nxt]) continue;
        ret += dfs(nxt);
    }
    return ret;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--, b--;
        MAP[b].push_back(a);
    }
    int mx = -1;
    for(int i = 0; i < N; i++){
        memset(visited, 0, sizeof(visited));
        answer[i] = dfs(i);
        mx = max(mx, answer[i]);
    }
    for(int i = 0; i < N; i++) if(mx == answer[i]) cout << i + 1 << " ";
    cout << "\n";
}