#include<bits/stdc++.h>
using namespace std;
#define MAX 20004
int V, E, K, u, v, w, cost[MAX];
vector<pair<int, int>> adj[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    scanf("%d %d %d", &V, &E, &K);
    fill(cost, cost + MAX, 1e9);
    for(int i = 0; i < E; i++){
        scanf("%d %d %d", &u, &v, &w);
        adj[u].push_back({w, v});
    }
    pq.push({0, K});
    cost[K] = 0;
    while(pq.size()){
        int from = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(dist != cost[from]) continue;
        for(pair<int, int> p : adj[from]){
            int to = p.second;
            int d = p.first;
            if(cost[to] > cost[from] + d){
                cost[to] = cost[from] + d;
                pq.push({cost[to], to});
            }
        }
    }
    for(int i = 1; i <= V; i++) {
        if(cost[i] == 1e9) printf("INF\n");
        else printf("%d\n", cost[i]);
    }
}