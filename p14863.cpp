#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, K, dp[MAX][104];
vector<pair<int, int>> walk(104), bike(104);
int go(int t, int idx){
    if(idx == N) return 0;
    int &ret = dp[t][idx];
    if(ret) return ret;
    ret = -1e9;
    if(t + walk[idx].first <= K) ret = max(ret, go(t + walk[idx].first, idx + 1) + walk[idx].second);
    if(t + bike[idx].first <= K) ret = max(ret, go(t + bike[idx].first, idx + 1) + bike[idx].second);
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> walk[i].first >> walk[i].second;
        cin >> bike[i].first >> bike[i].second;
    }
    cout << go(0, 0) << "\n";
}