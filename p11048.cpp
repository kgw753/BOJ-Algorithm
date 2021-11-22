#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, M;
int MAP[MAX][MAX];
int dp[MAX][MAX];
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> MAP[i][j];
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + MAP[i][j];
        }
    }
    cout << dp[N][M] << "\n";
}