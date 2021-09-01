#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int T, N, M, K, x, y, cnt, MAP[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void go(int y, int x){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(ny < 0 || nx < 0 || ny >= N || nx >= M || MAP[ny][nx] != 1) continue;
        MAP[ny][nx]++;
        go(ny, nx);
    }
}
int main(){
    cin >> T;
    while(T--){
        memset(MAP, 0, sizeof(MAP));
        cnt = 0;
        cin >> M >> N >> K;
        for(int i = 0; i < K; i++){
            cin >> x >> y;
            MAP[y][x] = 1;
        }
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(MAP[i][j] == 1){
                    go(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << "\n";
    }
}