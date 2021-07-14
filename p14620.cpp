#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int N, ans = 1e9;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> cost(MAX, vector<int>(MAX, 0));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void eraseVisited(int y, int x){
    visited[y][x] = false;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        visited[ny][nx] = false;
    }
}

bool nothing(int y, int x){
    if(visited[y][x]) return false;
    vector<pair<int, int>> v;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) return false;
        if(visited[ny][nx]) return false;
        v.push_back(make_pair(ny, nx));
    }
    for(pair<int, int> p: v) visited[p.first][p.second] = true;
    return true;
}

void dfs(int depth, int c){
    if(depth == 3){
        ans = min(ans, c);
        return;
    }

    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < N - 1; j++){
            if(nothing(i, j)){
                dfs(depth + 1, c + cost[i][j]);
                eraseVisited(i, j);
            }
        }
    }
}

int calcCost(int y, int x){
    int ret = MAP[y][x];
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) return -1;
        ret += MAP[ny][nx];
    }
    return ret;
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }

    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < N - 1; j++){
            cost[i][j] = calcCost(i, j);
        }
    }
    
    dfs(0, 0);
    cout << ans << "\n";
}