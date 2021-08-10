#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N, prev, cnt;
int dp[MAX], prevIdx[MAX]; // prevIdx ¿˙¿Â
vector<int> v;
void print(int idx){
    if(idx == 0) return;
    cnt++;
    v.push_back(idx);
    print(prevIdx[idx]);
}
int main(){
    cin >> N;
    memset(prevIdx, 0, sizeof(prevIdx));
    for(int i = 2; i <= N; i++){
        int cmp, d;
        if(i % 3 == 0 && i % 2 == 0) cmp = min(dp[i / 2], dp[i / 3]), d = (dp[i / 2] < dp[i / 3]) ? 2 : 3;
        else if(i % 3 == 0) cmp = dp[i / 3], d = 3;
        else if(i % 2 == 0) cmp = dp[i / 2], d = 2;
        else cmp = 1e9, d = 0;
        if(d == 0) prevIdx[i] = i - 1;
        else prevIdx[i] = (dp[i / d] > dp[i - 1]) ? i - 1 : i / d;
        dp[i] = min(cmp, dp[i - 1]) + 1;
        
    }
    print(N);
    cout << dp[N] << "\n";
    for(int i : v) cout << i << " ";
    cout << "\n";
}