#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
#define MAX_MOV 34
int T, W;
vector<int> v(MAX);
int dp[MAX][2][MAX_MOV];
int go(int sec, int pos, int mov){
    if(mov > W || sec == T) return 0;
    int &ret = dp[sec][pos][mov];
    if(~ret) return ret;
    return ret = max(go(sec + 1, pos, mov), go(sec + 1, pos ^ 1, mov + 1)) + (v[sec] == pos);
}
int main(){
    cin >> T >> W;
    for(int i = 0; i < T; i++){
        cin >> v[i];
        v[i]--;
    }
    memset(dp, -1, sizeof(dp));
    cout << max(go(0, 0, 0), go(0, 1, 1)) << "\n";
}