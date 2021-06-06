#include<bits/stdc++.h>
using namespace std;

int N, M, K;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
void DFS(vector<vector<int>> map, vector<vector<bool>> &visited, int y, int x){
    if(visited[y][x] || map[y][x] == 0) return;
    visited[y][x] = true;
    
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx >= 0 && ny >= 0 && nx < N && ny < M){
            DFS(map, visited, ny, nx);
        }
    }
}

int main(){
    int tc;
    cin >> tc;
    vector<int> answer;
    for(int i = 0; i < tc; i++){
        cin >> N >> M >> K;
        vector<vector<int>> map(M, vector<int>(N, 0));
        for(int j = 0; j < K; j++){
            int x, y;
            cin >> x >> y;
            map[y][x]++;
        }

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        int cnt = 0;
        for(int p = 0; p < M; p++){
            for(int q = 0; q < N; q++){
                if(visited[p][q] == false && map[p][q] == 1){
                    DFS(map, visited, p, q);
                    cnt++;
                }
            }
        }
        answer.push_back(cnt);
    }

    for(int ans : answer){
        cout << ans << "\n";
    }
}