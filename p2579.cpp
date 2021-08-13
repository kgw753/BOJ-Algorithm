#include<bits/stdc++.h>
using namespace std;
#define MAX 304
int N;
vector<int> v(MAX, 0);
int dp[MAX];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    dp[0] = v[0], dp[1] = v[0] + v[1];
    for(int i = 2; i < N; i++){
        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }
    cout << dp[N - 1] << "\n";
}