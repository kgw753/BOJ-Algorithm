#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int N, M, ans = 1e9;
int MAP[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
struct CCTV{
    int type, y, x;
};
vector<CCTV> cams;
bool isCam(int num){
    return (num >= 1 && num <= 5);
}
int cntArea(){
    int ret = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] == 0) ret++;
        }
    }
    return ret;
}
void goStraight(int dir, int y, int x, vector<pair<int, int>> &v){
    while(true){
        x = x + dx[dir];
        y = y + dy[dir];
        if(x < 0 || y < 0 || x >= M || y >= N || MAP[y][x] == 6) break;
        if(isCam(MAP[y][x]) || MAP[y][x] == -1) continue;
        MAP[y][x] = -1;
        v.push_back({y, x});
    }
}
vector<pair<int, int>> goCCTV(int idx, int dir){
    vector<pair<int, int>> ret;
    if(cams[idx].type == 1){
        goStraight(dir, cams[idx].y, cams[idx].x, ret);
    }
    else if(cams[idx].type == 2){
        goStraight(dir, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 2) % 4, cams[idx].y, cams[idx].x, ret);

    }
    else if(cams[idx].type == 3){
        goStraight((dir + 1) % 4, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 2) % 4, cams[idx].y, cams[idx].x, ret);
    }
    else if(cams[idx].type == 4){
        goStraight((dir + 1) % 4, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 2) % 4, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 3) % 4, cams[idx].y, cams[idx].x, ret);
    }
    else if(cams[idx].type == 5){
        goStraight(dir, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 1) % 4, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 2) % 4, cams[idx].y, cams[idx].x, ret);
        goStraight((dir + 3) % 4, cams[idx].y, cams[idx].x, ret);
    }
    return ret;
}
void dfs(int n){
    if(n == cams.size()){
        ans = min(ans, cntArea());
        return;
    }
    for(int i = 0; i < 4; i++){
        vector<pair<int, int>> tmp = goCCTV(n, i);
        dfs(n + 1);
        for(pair<int, int> p : tmp){
            if(isCam(MAP[p.first][p.second])) continue;
            MAP[p.first][p.second] = 0;
        }
    }
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(isCam(MAP[i][j])){
                cams.push_back({MAP[i][j], i, j});
            }
        }
    }
    dfs(0);
    cout << ans << "\n";
}