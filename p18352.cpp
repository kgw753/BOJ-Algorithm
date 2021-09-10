#include<bits/stdc++.h>
using namespace std;
#define MAX 300004
int N, M, K, X, a, b, cost[MAX];
vector<int> MAP[MAX], ans;
queue<int> q;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K >> X;
    fill(cost, cost + MAX, 1e9);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        MAP[a].push_back(b);
    }
    q.push(X);
    cost[X] = 0;
    while(q.size()){
        int here = q.front();
        q.pop();
        for(int there : MAP[here]){
            if(cost[there] > cost[here] + 1){
                cost[there] = cost[here] + 1;
                q.push(there);
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(cost[i] == K) ans.push_back(i);
    }
    if(ans.empty()) cout << -1 << "\n";
    else for(int a : ans) cout << a << "\n";
}