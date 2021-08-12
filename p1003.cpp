#include<bits/stdc++.h>
using namespace std;
#define MAX 44
int T, N;
vector<pair<int, int>> dp(MAX);
int main(){
    cin >> T;
    dp[0] = {1, 0};
    dp[1] = {0, 1};
    for(int i = 2; i <= MAX; i++){
        dp[i].first = dp[i - 1].first + dp[i - 2].first;
        dp[i].second = dp[i - 1].second + dp[i - 2].second;
    }
    while(T--){
        cin >> N;
        cout << dp[N].first << " " << dp[N].second << "\n";
    }
}