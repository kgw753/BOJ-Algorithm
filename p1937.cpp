#include<bits/stdc++.h>
using namespace std;
#define MAX 504
int N, MAP[MAX][MAX], dp[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int go(int y, int x){
    int &ret = dp[y][x];
    if(ret) return ret;
    int mx = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || MAP[y][x] >= MAP[ny][nx]) continue;
        mx = max(mx, go(ny, nx));
    }
    return ret = mx + 1;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    int res = -1, cnt;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res = max(res, go(i, j));
        }
    }
    cout << res << "\n";
}