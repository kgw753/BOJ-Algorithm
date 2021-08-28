#include<bits/stdc++.h>
using namespace std;
#define MAX 104
typedef long long ll;
ll N, S, E, M, a, b, c, cost[MAX], money[MAX];
vector<pair<ll, ll>> MAP[MAX];
bool check(ll from, ll to){
    int visited[MAX];
    memset(visited, 0, sizeof(visited));
    priority_queue<ll> pq;
    visited[from] = 1;
    pq.push(from);
    while(pq.size()){
        ll here = pq.top();
        pq.pop();
        for(int i = 0; i < MAP[here].size(); i++){
            ll there = MAP[here][i].second;
            if(visited[there]) continue;
            visited[there] = 1;
            pq.push(there);
        }
    }
    return visited[to];
}
int main(){
    fill(cost, cost + MAX, -1e9);
    cin >> N >> S >> E >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        MAP[a].push_back({-c, b});
    }
    for(int i = 0; i < N; i++) cin >> money[i];
    cost[S] = money[S];
    int flag = 0;
    for(int i = 0; i < N; i++){
        for(int here = 0; here < N; here++){
            if(cost[here] == -1e9) continue;
            for(pair<ll, ll> there : MAP[here]){
                ll there_idx = there.second;
                ll there_cost = there.first;
                if(cost[there_idx] < cost[here] + there_cost + money[there_idx]){
                    if(i == N - 1 && check(here, E)) flag = 1;
                    cost[there_idx] = cost[here] + there_cost + money[there_idx];
                }
            }
        }
    }
    if(cost[E] == -1e9) cout << "gg\n";
    else if(flag) cout << "Gee\n";
    else cout << cost[E] << "\n";
}