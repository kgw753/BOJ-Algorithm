#include<bits/stdc++.h>
using namespace std;
int N, K;
vector<int> coins;
long long answer;

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        int v;
        cin >> v;
        coins.push_back(v);
    }
    
    sort(coins.begin(), coins.end());

    vector<int> dp(K + 1, 0);

    for(int i = 0; i < N; i++){
        dp[coins[i]]++;
        for(int j = coins[i]; j < K + 1; j++){
            dp[j] += dp[j - coins[i]];
        }
    }

    cout << dp[K] << "\n";
}