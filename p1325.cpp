#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, M, a, b, mx = -1;
int cnt[MAX], visited[MAX];
vector<int> MAP[MAX];
int dfs(int node){
    visited[node] = 1;
    int ret = 1;
    for(int i = 0; i < MAP[node].size(); i++){
        if(visited[MAP[node][i]]) continue;
        ret += dfs(MAP[node][i]);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--, b--;
        MAP[b].push_back(a);
    }
    for(int i = 0; i < N; i++){
        memset(visited, 0, sizeof(visited));
        cnt[i] = dfs(i);
        mx = max(mx, cnt[i]);
    }
    for(int i = 0; i < N; i++){
        if(cnt[i] == mx) cout << i + 1 << " ";
        // cout << cnt[i] << "\n";
    }
    cout << "\n";
}