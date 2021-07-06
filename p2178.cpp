#include<bits/stdc++.h>
using namespace std;
#define MAX 101

int N, M;
string input;
int dx[] = {1, 0, -1 ,0};
int dy[] = {0, 1, 0, -1};
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[y][x] = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if(MAP[ny][nx] == 1 && visited[ny][nx] == 0){
                q.push(make_pair(nx, ny));
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < input.length(); j++){
            MAP[i][j] = input[j] - '0';
        }
    }

    bfs(0, 0);
    cout << visited[N - 1][M - 1] << "\n";
}