#include<bits/stdc++.h>
using namespace std;
int N, K, val;
int dp[10004];
int main(){
    cin >> N >> K;
    fill(dp, dp + 10004, 1e9);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> val;
        if(val > 10000) continue;
        for(int j = val; j <= K ; j++){
            dp[j] = min(dp[j], dp[j - val] + 1);
        }
    }
    if(dp[K] == 1e9) dp[K] = -1;
    cout << dp[K] << "\n";
}