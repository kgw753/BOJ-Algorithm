#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N;
int dp[MAX];
int main(){
    cin >> N;
    dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i - 1] +  dp[i - 2]) % 15746;
    }
    cout << dp[N] << "\n";
}