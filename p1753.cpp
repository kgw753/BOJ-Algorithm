#include<bits/stdc++.h>
using namespace std;
#define MAX 20004
int V, E, start, a, b, c;
vector<vector<pair<int, int>>> MAP(MAX, vector<pair<int, int>>());
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cost[MAX];
void go(int start){
    pq.push({0, start});
    cost[start] = 0;
    while(pq.size()){
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();
        if(here_cost != cost[here]) continue;
        for(pair<int, int> p : MAP[here]){
            int there = p.second;
            int there_cost = p.first;
            if(there_cost + here_cost < cost[there]){
                cost[there] = there_cost + here_cost;
                pq.push({cost[there], there});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(cost, cost + MAX, 1e9);
    cin >> V >> E >> start;
    pq.push({0, start});
    for(int i = 0; i < E; i++){
        cin >> a >> b >> c;
        MAP[a].push_back({c, b});
    }
    go(start);
    for(int i = 1; i <= V; i++){
        if(cost[i] == 1e9) cout << "INF\n";
        else cout << cost[i] << "\n";
    }
}