#include<bits/stdc++.h>
using namespace std;
#define MAX 804
vector<pair<int, int>> MAP[MAX];
int N, E, a, b, c;
int v1, v2;
int dist[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void go(int start){
    fill(dist, dist + MAX, 1e9);
    pq.push({0, start});
    dist[start] = 0;
    while(pq.size()){
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();
        if(dist[here] != here_cost) continue;
        for(pair<int, int> p : MAP[here]){
            int there = p.second;
            int there_cost = p.first;
            if(dist[there] > dist[here] + there_cost){
                dist[there] = dist[here] + there_cost;
                pq.push({dist[there], there});
            }
        }
    }
}
int main(){
    cin >> N >> E;
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        MAP[a].push_back({c, b});
        MAP[b].push_back({c, a});
    }
    cin >> v1 >> v2;
    bool noWay1 = false;
    bool noWay2 = false;
    go(1);
    if(dist[v1] == 1e9) noWay1 = true;
    if(dist[v2] == 1e9) noWay2 = true;
    int r1 = dist[v1];
    int r2 = dist[v2];
    
    go(v2);
    if(dist[N] == 1e9 || dist[v1] == 1e9) noWay1 = true;
    else r1 += (dist[N] + dist[v1]);

    go(v1);
    if(dist[N] == 1e9 || dist[v2] == 1e9) noWay2 = true;
    else r2 += (dist[N] + dist[v2]);
    
    int res = 1e9;
    if(noWay1 && noWay2) res = -1;
    else res = min(r1, r2);
    cout << res << "\n";
}

