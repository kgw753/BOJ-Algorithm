#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, M, C, y, x, MAP[MAX][MAX], dp[MAX][MAX][MAX][MAX];
int dx[] = {1, 0}, dy[] = {0, 1};
const int mod = 1000007;
int go(int y, int x, int cnt, int prev){
    if(y == N - 1 && x == M - 1){
        if(cnt == 0 && MAP[y][x] == 0) return 1;
        if(cnt == 1 && MAP[y][x] > prev) return 1;
        return 0;
    }
    int &ret = dp[y][x][cnt][prev];
    if(~ret) return ret;
    ret = 0;
    for(int i = 0; i < 2; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if(MAP[y][x] > prev) ret = (ret + go(ny, nx, cnt - 1, MAP[y][x])) % mod;
        else if(MAP[y][x] == 0) ret = (ret + go(ny, nx, cnt, prev)) % mod;
    }
    return ret;
}
int main(){
    cin >> N >> M >> C;
    for(int i = 1; i <= C; i++){
        cin >> y >> x;
        MAP[y - 1][x - 1] = i;
    }
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i <= C; i++) {
        cout << go(0, 0, i, 0) << "\n";
    }
}