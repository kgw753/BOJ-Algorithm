#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, M, H, total, cnt;
int MAP[MAX][MAX][MAX];
struct Pos{
    int z, y, x;
};
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};
queue<Pos> q;
bool outOfRange(int z, int y, int x){
    if(z < 0 || y < 0 || x < 0 || z >= H || y >= N || x >= M) return true;
    return false;
}
void go(){
    queue<Pos> tmp;
    while(q.size()){
        Pos here = q.front();
        cnt++;
        q.pop();
        for(int i = 0; i < 6; i++){
            int nx = here.x + dx[i];
            int ny = here.y + dy[i];
            int nz = here.z + dz[i];
            if(outOfRange(nz, ny, nx)) continue;
            else if(MAP[nz][ny][nx] == 0){
                MAP[nz][ny][nx] = 1;
                tmp.push({nz, ny, nx});
            }
        }
    }
    q = tmp;
}
int main(){
    cin >> M >> N >> H;
    total = M * N * H;
    for(int h = 0; h < H; h++){
        for(int n = 0; n < N; n++){
            for(int m = 0; m < M; m++){
                cin >> MAP[h][n][m];
                if(MAP[h][n][m] == 1){
                    q.push({h, n, m});
                }
                else if(MAP[h][n][m] == -1){
                    total--;
                }
            }
        }
    }
    int day = 0;
    while(true){
        go();
        if(q.empty()) break;
        day++;
    }
    if(total == cnt) cout << day << "\n";
    else cout << -1 << "\n";
}