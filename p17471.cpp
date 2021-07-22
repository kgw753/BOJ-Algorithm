#include<bits/stdc++.h>
using namespace std;
#define MAX 14
int N, Ecnt, E, p1, p2, ans = 1e9, cnt1, cnt2;
vector<int> people(MAX, 0), visited(MAX, 0);
vector<vector<int>> TREE(MAX, vector<int>());
vector<int> group(MAX, 0);

void dfs(int node, int flag){
    visited[node] = 1;
    if(flag == 1) cnt1++, p1 += people[node];
    else cnt2++, p2 += people[node];
    for(int i = 0; i < TREE[node].size(); i++){
        if(group[TREE[node][i]] != flag) continue;
        if(visited[TREE[node][i]] == 0) dfs(TREE[node][i], flag);
    }
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> people[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> Ecnt;
        for(int j = 0; j < Ecnt; j++){
            cin >> E;
            TREE[i].push_back(E);
            TREE[E].push_back(i);
        }
    }
    for(int i = 1; i < (1 << N) - 1; i++){
        p1 = p2 = cnt1 = cnt2 = 0;
        int s1, s2;
        fill(visited.begin(), visited.end(), 0);
        fill(group.begin(), group.end(), 1);
        for(int idx = 0; idx < N; idx++){
            if((1 << idx) & i)  s1 = idx + 1;
            else s2 = idx + 1, group[idx + 1] = 2;
        }
        dfs(s1, 1);
        dfs(s2, 2);
        if(cnt1 + cnt2 == N) {
            ans = min(ans, abs(p1 - p2));
        }
    }
    if(ans == 1e9) ans = -1;
    cout << ans << "\n";
}