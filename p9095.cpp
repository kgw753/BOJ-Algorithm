#include<bits/stdc++.h>
using namespace std;
int T, N;
int dp[15];
int go(int n){
    int &ret = dp[n];
    if(ret) return ret;
    return ret = go(n - 1) + go(n - 2) + go(n - 3);
}
int main(){
    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    cin >> T;
    while(T--){
        cin >> N;
        cout << go(N) << "\n";
    }
}