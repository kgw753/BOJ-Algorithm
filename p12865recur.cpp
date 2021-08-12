#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, K;
vector<int> w(MAX, 0), v(MAX, 0);
int dp[100004][MAX];
int go(int idx, int now){
    if(idx == N) return 0;
    int &ret = dp[now][idx];
    if(ret) return ret;
    int r1, r2;
    if(now + w[idx] > K) r1 = 0;
    else r1 = go(idx + 1, now + w[idx]) + v[idx];
    r2 = go(idx + 1, now);
    return ret = max(r1, r2);
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    cout << go(0, 0) << "\n";
}