#include<bits/stdc++.h>
using namespace std;
#define MAX 104
#define w_MAX 100004
int N, K;
vector<int> w(MAX, 0), v(MAX, 0);
int dp[MAX][w_MAX];
int go(int idx, int weight){
    if(idx == N) return 0;
    int &ret = dp[idx][weight];
    if(ret) return ret;
    int yes = (weight + w[idx] > K) ? 0 : go(idx + 1, weight + w[idx]) + v[idx];
    int no = go(idx + 1, weight);
    return ret = max(yes, no);
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    cout << go(0, 0) << "\n";
}