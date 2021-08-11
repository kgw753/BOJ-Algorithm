#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, K, num;
int dp[10004];
int main(){
    cin >> N >> K;
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        cin >> num;
        for(int j = num; j <= K; j++){
            dp[j] += dp[j - num];
        }
    } 
    cout << dp[K] << "\n";
}