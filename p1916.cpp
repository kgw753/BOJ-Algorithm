#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, M, a, b, c;
int cost[MAX];
vector<vector<pair<int, int>>> MAP(MAX, vector<pair<int, int>>());
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        MAP[a].push_back({c, b});
    }
    int here, here_cost, dest;
    fill(cost, cost + MAX, 1e9);
    cin >> here >> dest;
    pq.push({0, here});
    cost[here] = 0;
    while(pq.size()){
        here = pq.top().second;
        here_cost = pq.top().first;
        pq.pop();
        if(cost[here] != here_cost)continue;
        for(pair<int, int> p : MAP[here]){
            int there = p.second;
            int there_cost = p.first;
            if(cost[there] > cost[here] + there_cost){
                cost[there] = cost[here] + there_cost;
                pq.push({cost[there], there});
            }
        }
    }
    cout << cost[dest] << "\n";
}