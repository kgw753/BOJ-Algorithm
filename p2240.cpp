#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
#define MAX_MOV 34
int T, W;
vector<int> v(MAX);
int dp[MAX][2][MAX_MOV];
int go(int t, int pos, int rem){
    if(rem < 0) return -1;
    if(t == T) return 0;
    int &ret = dp[t][pos][rem];
    if(~ret) return ret;
    return ret = max(go(t + 1, pos, rem), go(t + 1, !pos, rem - 1)) + (v[t] == pos);
}
int main(){
    cin >> T >> W;
    for(int i = 0; i < T; i++){
        cin >> v[i];
        v[i]--;
    }
    memset(dp, -1, sizeof(dp));
    cout << max(go(0, 0, W), go(0, 1, W - 1)) << "\n";
}