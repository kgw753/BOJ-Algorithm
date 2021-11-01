#include<bits/stdc++.h>
using namespace std;
#define MAX 17
int N;
int dp[MAX];
vector<pair<int, int>> v(MAX);
int go(int d){
    if(d > N) return -1e9;
    if(d == N) return 0;
    int &ret = dp[d];
    if(~ret) return ret;
    return ret = max(go(d + 1), go(d + v[d].first) + v[d].second);
}
int main(){
    cin >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < N; i++){
        cin >> v[i].first >> v[i].second;
    }
    cout << go(0) << "\n";
}