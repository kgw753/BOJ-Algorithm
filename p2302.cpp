#include<bits/stdc++.h>
using namespace std;
#define MAX 42
int N, M, now, pre, dp[MAX], ans = 1;
void fillDp(){
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i < MAX; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}
int main(){
    cin >> N >> M;
    fillDp();
    for(int i = 0; i < M; i++) {
        cin >> now;
        ans *= dp[(now - 1) - pre];
        pre = now; 
    }
    ans *= dp[N - pre];
    cout << ans << "\n";
}