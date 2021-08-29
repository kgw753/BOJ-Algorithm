#include<bits/stdc++.h>
using namespace std;
#define MAX 27
int N, M, T, D, x, y, MAP[MAX][MAX], cost_go[MAX][MAX], cost_back[MAX][MAX];
string input;
struct Pos{
    int y, x;
};
queue<pair<int, Pos>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&cost_go[0][0], &cost_go[0][0] + MAX * MAX, 1e9);
    fill(&cost_back[0][0], &cost_back[0][0] + MAX * MAX, 1e9);
    cin >> N >> M >> T >> D;    // T : 최대 높이 차이, D : 제한 시간
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = (input[j] >= 'A' && input[j] <= 'Z') ? input[j] - 'A' : input[j] - 'a' + 26;
        }
    }
    cost_go[0][0] = 0;
    q.push({0, {0, 0}});
    while(q.size()){
        int x = q.front().second.x;
        int y = q.front().second.y;
        int here_cost = q.front().first;
        q.pop();
        if(cost_go[y][x] != here_cost) continue;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            int diff = MAP[ny][nx] - MAP[y][x];
            if(abs(diff) > T) continue;
            int there_cost = (diff > 0) ? (diff * diff) : 1;
            if(cost_go[ny][nx] > cost_go[y][x] + there_cost){
                cost_go[ny][nx] = cost_go[y][x] + there_cost;
                q.push({cost_go[ny][nx], {ny, nx}});
            }
        }
    }
    cost_back[0][0] = 0;
    q.push({0, {0, 0}});
    while(q.size()){
        int x = q.front().second.x;
        int y = q.front().second.y;
        int here_cost = q.front().first;
        q.pop();
        if(cost_back[y][x] != here_cost) continue;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
            int diff = MAP[ny][nx] - MAP[y][x];
            if(abs(diff) > T) continue;
            int there_cost = (diff < 0) ? (diff * diff) : 1;
            if(cost_back[ny][nx] > cost_back[y][x] + there_cost){
                cost_back[ny][nx] = cost_back[y][x] + there_cost;
                q.push({cost_back[ny][nx], {ny, nx}});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(cost_go[i][j] + cost_back[i][j] <= D) ans = max(ans, MAP[i][j]);
        }
    }
    cout << ans << "\n";
}