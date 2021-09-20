#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, dp[MAX][3];
vector<int> v(MAX, 0);
int go(int idx, int check){
    if(idx == N) return 0;
    int &ret = dp[idx][check];
    if(~ret) return ret;
    ret = go(idx + 1, 0);
    if(check == 0) ret = max(ret, go(idx + 1, 1) + v[idx]);
    if(check == 1) ret = max(ret, go(idx + 1, 2) + v[idx]);
    return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0) << "\n";
}