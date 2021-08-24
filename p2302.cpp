#include<bits/stdc++.h>
using namespace std;
#define MAX 44
int N, M, s, e, dp[MAX], ans = 1;
int main(){
    dp[0] = dp[1] = 1;
    for(int i = 2; i < MAX; i++) dp[i] = dp[i - 1] + dp[i - 2];
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> e;
        ans *= dp[(e - 1) - s];
        s = e;
    }
    ans *= dp[N - s];
    cout << ans << "\n";
}