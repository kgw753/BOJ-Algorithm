#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int N, M;
string input;
vector<vector<char>> MAP(MAX, vector<char>(MAX));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int maxVal(){
    int ret = -1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            ret = max(ret, visited[i][j]);
        }
    }
    return ret;
}

void bfs(int y, int x){
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            if(MAP[ny][nx] == 'L' && visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int solve(int y, int x){
    bfs(y, x);
    return maxVal();
}

void clearVisited(){
    for(int i = 0; i < N; i++){
        fill(visited[i].begin(), visited[i].begin() + M, 0);
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
        }
    }

    int res = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(MAP[i][j] == 'L'){
                clearVisited();
                visited[i][j] = 1;  // 이걸 지우고 res를 출력하면 오답ㅠㅠㅠ
                res = max(res, solve(i, j));
            }
        }
    }
    cout << res - 1 << "\n";
}