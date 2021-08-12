#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, K, ans;
vector<int> v(MAX, 0), w(MAX, 0);
int dp[100004];
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> w[i] >> v[i];
    for(int i = 0; i < N; i++){
        for(int j = K; j >= w[i]; j--){
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[K] << "\n";
}