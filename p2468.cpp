#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, mn = 1e9, mx = -1, MAP[MAX][MAX], visited[MAX][MAX], res = 1;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int y, int x, int h){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(MAP[ny][nx] <= h || visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, h);
    }
}
int go(int h){
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(MAP[i][j] > h && visited[i][j] == 0){
                visited[i][j] = 1;
                dfs(i, j, h);
                ret++;
            }
        }
    }
    return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            mn = min(mn, MAP[i][j]);
            mx = max(mx, MAP[i][j]);
        }
    }
    for(int i = mn; i < mx; i++){
        res = max(res, go(i));
    }
    cout << res << "\n";
}