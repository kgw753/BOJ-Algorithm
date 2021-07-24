#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int N, M, cnt, area = 1, tmp, sum;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int wall[] = {4, 8, 1, 2};

void visitedClear(){
    for(int i = 0; i < N; i++) fill(visited[i].begin(), visited[i].end(), 0);
}
void print(){
    for(int i = 0 ; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
void dfs(int y, int x){
    tmp++;
    for(int i = 0; i < 4; i++){
        if(MAP[y][x] & wall[i]) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx]) continue;
        visited[ny][nx] = visited[y][x] + 1;
        dfs(ny, nx);
    }
}
int main(){
    cin >> M >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(visited[i][j]) continue;
            visited[i][j] = 1;
            tmp = 0;
            dfs(i, j);
            area = max(area, tmp);
            cnt++;
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < 4; k++){
                if(MAP[i][j] & wall[k]){
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
                    visitedClear();
                    int idx;
                    if(k <= 1) idx = k + 2;
                    else idx = k - 2;
                    MAP[ny][nx] -= wall[idx];
                    MAP[i][j] -= wall[k];
                    tmp = -1;
                    dfs(i, j);
                    sum = max(sum, tmp);
                    MAP[ny][nx] += wall[idx];
                    MAP[i][j] += wall[k];
                }
            }
        }
    }

    cout << cnt << "\n";
    cout << area << "\n";
    cout << sum << "\n";
}