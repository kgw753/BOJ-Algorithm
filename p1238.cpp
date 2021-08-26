#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, M, X, u, v, t, ans, cost[MAX], goHome[MAX];
vector<pair<int, int>> MAP[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> t;
        MAP[u].push_back({t, v});
    }
    fill(goHome, goHome + MAX, 1e9);
    pq.push({0, X});
    goHome[X] = 0;
    while(pq.size()){
        int here = pq.top().second;
        int here_time = pq.top().first;
        pq.pop();
        if(goHome[here] != here_time) continue;
        for(int i = 0; i < MAP[here].size(); i++){
            int there = MAP[here][i].second;
            int there_time = MAP[here][i].first;
            if(goHome[there] > goHome[here] + there_time){
                goHome[there] = goHome[here] + there_time;
                pq.push({goHome[there], there});
            }
        }
    }

    for(int i = 1; i <= N; i++){
        fill(cost, cost + MAX, 1e9);
        while(pq.size()) pq.pop();
        if(i == X) continue;
        cost[i] = 0;
        pq.push({0, i});
        while(pq.size()){
            int here = pq.top().second;
            int here_time = pq.top().first;
            pq.pop();
            if(cost[here] != here_time) continue;
            for(int i = 0; i < MAP[here].size(); i++){
                int there = MAP[here][i].second;
                int there_time = MAP[here][i].first;
                if(cost[there] > cost[here] + there_time){
                    cost[there] = cost[here] + there_time;
                    pq.push({cost[there], there});
                }
            }
        }
        ans = max(ans, cost[X] + goHome[i]);
    }
    cout << ans << "\n";
}