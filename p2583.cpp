#include<bits/stdc++.h>
using namespace std;
#define MAX 101

int N, M, K, depth;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<vector<bool>> area(MAX, vector<bool>(MAX, false));
vector<int> answer;

void filling(int sx, int sy, int ex, int ey){
    for(int i = sy; i < ey; i++){
        for(int j = sx; j < ex; j++){
            area[i][j] = true;
        }
    }
}

void dfs(int x, int y){
    area[y][x] = true;
    depth++;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if(area[ny][nx] == false){
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> M >> N >> K;
    int sx, sy, ex, ey;
    for(int i = 0; i < K; i++){
        cin >> sx >> sy >> ex >> ey;
        filling(sx, sy, ex, ey);
    }

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(area[i][j] == false){
                dfs(j, i);
                answer.push_back(depth);
                depth = 0;
            }
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for(int ans: answer) cout << ans << " ";
    cout << "\n";
}