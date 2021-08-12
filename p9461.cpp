#include<bits/stdc++.h>
using namespace std;
#define MAX 104
typedef long long ll;
int T, N;
ll dp[MAX];
int main(){
    cin >> T;
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    for(int i = 6; i < MAX; i++) dp[i] = dp[i - 1] + dp[i - 5];
    while(T--){
        cin >> N;
        cout << dp[N] << "\n";
    }
}