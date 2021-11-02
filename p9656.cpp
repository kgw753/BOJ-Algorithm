#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, dp[MAX];
int main(){
    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for(int i = 4; i <= N; i++){
        if(dp[i - 1] || dp[i - 3]) dp[i] = 0;
        else dp[i] = 1;
    }
    if(dp[N]) cout << "SK\n";
    else cout << "CY\n";
}