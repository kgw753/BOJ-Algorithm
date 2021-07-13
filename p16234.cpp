#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int N, L, R, ans;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> uni;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void move(int people){
    for(pair<int, int> p: uni) MAP[p.first][p.second] = people / uni.size();
}

int people(){
    int ret = 0;
    for(pair<int, int> p: uni) ret += MAP[p.first][p.second];
    return ret;
}

bool haveGap(int y, int x){
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        int gap = abs(MAP[y][x] - MAP[ny][nx]);
        if(gap >= L && gap <= R) return true;
    }
    return false;
}

void dfs(int y, int x){
    uni.push_back(make_pair(y, x));
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        int gap = abs(MAP[y][x] - MAP[ny][nx]);
        if(gap >= L && gap <= R && visited[ny][nx] == 0){
            dfs(ny, nx);
        }
    }
}
int main(){
    cin >> N >> L >> R;
    for(int i = 0; i < N; i++){
        for(int j = 0; j< N; j++){
            cin >> MAP[i][j];
        }
    }

    bool next = true;
    while(next){
        next = false;
        for(int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), 0);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(visited[i][j] == 0 && haveGap(i, j)){
                    dfs(i, j);
                    int sum = people();
                    move(sum);
                    uni.clear();
                    next = true;
                }
            }
        }
        ans++;
    }
    cout << ans - 1 << "\n";
}