#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int N, M, ans = -1;
string input;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> land;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void clearVisited(){
    for(int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].begin() + M, 0);
}

void bfs(pair<int, int> pos){
    queue<pair<int, int>> q;
    q.push(pos);
    visited[pos.first][pos.second] = 1;
    while(!q.empty()){
        int x = q.front().second;
        int y = q.front().first;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] || MAP[ny][nx] == 'W') continue;
            visited[ny][nx] = visited[y][x] + 1;
            ans = max(ans, visited[ny][nx]);
            q.push(make_pair(ny, nx));
        }
    }

}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
            if(MAP[i][j] == 'L') land.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < land.size(); i++){
        bfs(land[i]);
        clearVisited();
    }
    cout << ans - 1 << "\n";
}