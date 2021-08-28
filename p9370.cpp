#include<bits/stdc++.h>
using namespace std;
#define MAX 2004
int T, dist[MAX], dist2[MAX];
int n, m, t, s, g, h, a, b, d;
vector<pair<int, int>> MAP[MAX];
vector<int> ans, cand(104, 0);
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq, pq2;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> t; // 교차로, 도로, 후보의 갯수
        cin >> s >> g >> h; // 출발 교차로, 지나는 도로를 갖는 두 개 의 교차로
        s--, g--, h--;
        for(int i = 0; i < n; i++) MAP[i].clear();
        ans.clear();
        fill(dist, dist + MAX, 1e9);
        fill(dist2, dist2 + MAX, 1e9);
        for(int i = 0; i < m; i++){
            cin >> a >> b >> d; // 출발, 도착, 거리
            a--, b--;
            MAP[a].push_back({d, b});
            MAP[b].push_back({d, a});
        }
        for(int i = 0; i < t; i++){
            cin >> cand[i];
        }
        pq.push({0, s});
        dist[s] = 0;
        while(pq.size()){
            int here = pq.top().second;
            int here_dist = pq.top().first;
            pq.pop();
            if(dist[here] != here_dist) continue;
            for(int i = 0; i < MAP[here].size(); i++){
                int there = MAP[here][i].second;
                int there_dist = MAP[here][i].first;
                if(dist[there] > dist[here] + there_dist){
                    dist[there] = dist[here] + there_dist;
                    pq.push({dist[there], there});
                }
            }
        }
        int start = dist[g] > dist[h] ? g : h;
        int start_dist = max(dist[g], dist[h]);
        pq2.push({0, start});
        dist2[start] = 0;
        while(pq2.size()){
            int here = pq2.top().second;
            int here_dist = pq2.top().first;
            pq2.pop();
            if(dist2[here] != here_dist) continue;
            for(int i = 0; i < MAP[here].size(); i++){
                int there = MAP[here][i].second;
                int there_dist = MAP[here][i].first;
                if(dist2[there] > dist2[here] + there_dist){
                    dist2[there] = dist2[here] + there_dist;
                    pq2.push({dist2[there], there});
                }
            }
        }
        for(int i = 0; i < t; i++){
            int idx = cand[i] - 1;
            if(dist[idx] == start_dist + dist2[idx]) ans.push_back(idx + 1);
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << "\n";
    }
}