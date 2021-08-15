#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, cost[MAX][3], dp[MAX][3];
int go(int n, int color){
    if(n == N) return 0;
    int &ret = dp[n][color];
    if(ret != 1e9) return ret;
    for(int i = 0; i < 3; i++){
        if(color == i) continue;
        ret = min(ret, go(n + 1, i) + cost[n][color]);
    }
    return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    for(int i = 0; i < N; i++) fill(dp[i], dp[i] + 3, 1e9);
    int res = 1e9;
    for(int i = 0; i < 3; i++){
        res = min(res, go(0, i));
    }
    cout << res << "\n";
}