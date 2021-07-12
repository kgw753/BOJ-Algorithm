#include<bits/stdc++.h>
using namespace std;
#define MAX 5
int N, M, K;
string input;
pair<int, int> from, to;
vector<vector<char>> MAP(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int y, int x){
    if(visited[y][x] == K){
        if(y == to.first && x == to.second) return 1;
        return 0;
    }
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx] != 0 || MAP[ny][nx] == 'T') continue;
        visited[ny][nx] = visited[y][x] + 1;
        ret += dfs(ny, nx);
        visited[ny][nx] = 0;
    }
    return ret;
}

int main(){
    cin >> N >> M >> K;
    from = make_pair(N - 1, 0);
    to = make_pair(0, M - 1);
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
        }
    }
    visited[from.first][from.second] = 1;
    cout << dfs(from.first, from.second) << "\n";
}