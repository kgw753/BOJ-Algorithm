#include<bits/stdc++.h>
using namespace std;
int T, N;
int dp[10004];
int main(){
    cin >> T;
    dp[0] = 1;
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= 10000; j++){
            if(j - i >= 0) dp[j] += dp[j - i];
        }
    }
    while(T--){
        cin >> N;
        cout << dp[N] << "\n";
    }
}