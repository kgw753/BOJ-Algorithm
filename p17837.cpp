#include<bits/stdc++.h>
using namespace std;
#define MAX 15
int N, K, x, y, dir, res, flag;
int dx[] = {0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
struct Point{
    int y, x, dir;
};
vector<int> pieces[MAX][MAX];
vector<Point> pos;
bool gameOver(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(pieces[i][j].size() >= 4) return true;
        }
    }
    return false;
}
int reverseDir(int dir){
    if(dir % 2) return dir + 1;
    else return dir - 1;
}
void goPiece(int idx){
    x = pos[idx].x;
    y = pos[idx].y;
    dir = pos[idx].dir;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || ny < 0 || nx >= N || ny >= N || MAP[ny][nx] == 2){
        pos[idx].dir = reverseDir(dir);
        nx = x + dx[pos[idx].dir];
        ny = y + dy[pos[idx].dir];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N || MAP[ny][nx] == 2) return;
    }
    vector<int> &now = pieces[y][x];
    vector<int> &nxt = pieces[ny][nx];
    auto p = find(now.begin(), now.end(), idx);
    if(MAP[ny][nx] == 1) reverse(p, now.end());
    for(auto i = p; i != now.end(); i++){
        pos[*i].y = ny;
        pos[*i].x = nx;
        nxt.push_back(*i);
    }
    now.erase(p, now.end());
    return;
}
bool goTurn(){
    for(int i = 0; i < K; i++){
        goPiece(i);
        if(gameOver()) return true;
    }
    return false;
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        cin >> y >> x >> dir;
        x--, y--;
        pieces[y][x].push_back(i);
        pos.push_back({y, x, dir});
    }
    while(res <= 1000){
        res++;
        if(goTurn()){
            flag = 1;
            break;
        }
    }
    if(flag) cout << res << "\n";
    else cout << -1 << "\n";
}