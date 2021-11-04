#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, r1, r2;
string input;
char MAP[MAX][MAX];
int visited[MAX][MAX];
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(int y, int x, bool colorBlind){
    q.push({y, x});
    visited[y][x] = 1;
    while(q.size()){
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx]) continue;
            if(colorBlind){
                if(abs(MAP[ny][nx] - MAP[y][x]) == abs('R' - 'G')){
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
                else if(MAP[ny][nx] == MAP[y][x]){
                    q.push({ny, nx});
                    visited[ny][nx] = visited[y][x] + 1;
                }
            }
            else if(MAP[ny][nx] == MAP[y][x]){
                q.push({ny, nx});
                visited[ny][nx] = visited[y][x] + 1;
            }
        }
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            MAP[i][j] = input[j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) continue;
            bfs(i, j, false);
            r1++;
        }
    }
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j]) continue;
            bfs(i, j, true);
            r2++;
        }
    }

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << r1 << " " << r2 << "\n";
}