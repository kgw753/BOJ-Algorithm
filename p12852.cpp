#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N;
vector<int> dp(MAX, 1e9);
void print(int idx){
    cout << idx << " ";
    if(idx == 1) return;
    if(idx % 3 == 0 && dp[idx] == dp[idx / 3] + 1) print(idx / 3);
    else if(idx % 2 == 0 && dp[idx] == dp[idx / 2] + 1) print(idx / 2);
    else if(dp[idx] == dp[idx - 1] + 1) print(idx - 1);
}
int main(){
    cin >> N;
    dp[1] = 0;
    for(int i = 2; i <= N; i++){
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        dp[i] = min(dp[i], dp[i - 1] + 1);
    }
    cout << dp[N] << "\n";
    print(N);
    cout << "\n";
}