#include<bits/stdc++.h>
using namespace std;
#define MAX 24
int N, ans;
vector<int> cost(MAX, 0), joy(MAX, 0);
int dp[MAX];
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> cost[i];
    for(int i = 0; i < N; i++) cin >> joy[i];
    for(int i = 0; i < N; i++){
        for(int j = 100; j > cost[i]; j--){
            dp[j] = max(dp[j],)
        }
    }
}