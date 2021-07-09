#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
int N, M, A, B, cnt;
vector<int> dp(MAX, 0);
vector<int> visited(MAX, false);
vector<vector<int>> relation(MAX, vector<int>());

int dfs(int k){
    visited[k] = true;
    int n = 1;
    for(int i = 0; i < relation[k].size(); i++){
        if(visited[relation[k][i]]) continue;
        n += dfs(relation[k][i]);
    }
    return n;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> A >> B;
        relation[B].push_back(A);
    }
    for(int i = 1; i <= N; i++){
        fill(visited.begin(), visited.begin() + N + 1, false);
        dp[i] = dfs(i);
        cnt = max(cnt, dp[i]);
    }

    for(int i = 1; i <= N; i++){
        if(cnt == dp[i]) cout << i << " ";
    }
    cout << "\n";
}