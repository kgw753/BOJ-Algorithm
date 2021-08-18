#include<bits/stdc++.h>
using namespace std;
#define MAX 104
typedef long long ll;
int N;
ll dp[MAX][21];
vector<int> v(MAX, 0);
ll go(int sum, int depth){
    if(sum < 0 || sum > 20) return 0;
    if(depth == N - 2) {
        return v[N - 1] == sum ? 1 : 0;
    }
    ll &ret = dp[depth][sum];
    if(ret != -1) return ret;
    return ret = go(sum + v[depth + 1], depth + 1) + go(sum - v[depth + 1], depth + 1);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    memset(dp, -1, sizeof(dp));
    cout << go(v[0], 0) << "\n";
}