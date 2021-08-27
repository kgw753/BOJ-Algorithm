#include<bits/stdc++.h>
using namespace std;
#define MAX 504
typedef long long ll;
ll N, M, K, a, b, c, dist[MAX];
vector<pair<ll, ll>> MAP[MAX];
int main(){
    fill(dist, dist + MAX, 1e9);
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        a--, b--;
        MAP[a].push_back({b, c});
    }
    dist[0] = 0;
    int flag = 0;
    for(int i = 0; i < N; i++){
        for(int here = 0; here < N; here++){
            for(pair<ll, ll> there : MAP[here]){
                ll there_idx = there.first;
                ll there_cost = there.second;
                if(dist[here] != 1e9 && dist[there_idx] > dist[here] + there_cost){
                    dist[there_idx] = dist[here] + there_cost;
                    if(i == N - 1) flag = 1;
                }
            }
        }
    }
    if(flag) cout << -1 << "\n";
    else {
        for(int i = 1; i < N; i++) {
            if(dist[i] == 1e9) cout << -1 << "\n";
            else cout << dist[i] << "\n";
        }
    }
}