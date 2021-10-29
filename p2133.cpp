#include<bits/stdc++.h>
using namespace std;
#define MAX 32
int N, dp[MAX];
int main(){
    cin >> N;
    dp[2] = 3;
    for(int i = 4; i < MAX; i += 2){
        dp[i] = dp[i - 2] + 2;
        for(int j = i - 2; j > 0; j -= 2){
            dp[i] += dp[j] * 2;
        }
    }
    cout << dp[N] << "\n";
}