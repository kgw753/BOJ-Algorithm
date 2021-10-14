#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, M, cnt;
int MAP[MAX][MAX], visited[MAX][MAX];
int y, x, dir;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
void go(int y, int x, int dir){
    int d = 0;
    while(true){
        if(visited[y][x] == 0) cnt++;
        visited[y][x] = 1;
        int i;
        for(i = 1; i <= 4; i++){
            int nd = (dir - i + 4) % 4;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            else if(MAP[ny][nx] == 0 && visited[ny][nx] == 0){
                y = ny;
                x = nx;
                dir = nd;
                break;
            }
        }
        if(i == 5){
            int nd = (dir + 2) % 4;
            int ny = y + dy[nd];
            int nx = x + dx[nd];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M || MAP[ny][nx]){
                return;
            }
            y = ny;
            x = nx;
        }
    }
    
}
int main(){
    cin >> N >> M;
    cin >> y >> x >> dir;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
    go(y, x, dir);
    cout << cnt << "\n";
}