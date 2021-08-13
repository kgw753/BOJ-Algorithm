#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int N;
int MAP[MAX][MAX], dp[MAX][MAX][3];
bool check(int y, int x, int d){
    if(d == 1){
        if(MAP[y][x] || MAP[y - 1][x] || MAP[y][x - 1]) return false;
    }
    else if(d == 0 || d == 2){
        if(MAP[y][x]) return false;
    }
    return true;
}
int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> MAP[i][j];
        }
    }
    dp[1][2][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];
            
            if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            if(check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if(check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if(check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
        }
    }
    cout << dp[N][N][0] + dp[N][N][1] + dp[N][N][2] << "\n";
}