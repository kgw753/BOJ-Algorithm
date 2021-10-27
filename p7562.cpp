#include<bits/stdc++.h>
using namespace std;
#define MAX 304
int T, L;
int sy, sx, ey, ex;
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int visited[MAX][MAX];
int main(){
    cin >> T;
    while(T--){
        cin >> L;
        cin >> sy >> sx >> ey >> ex;
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx] = 1;
        q.push({sy, sx});
        int y, x;
        while(q.size() && visited[ey][ex] == 0){
            y = q.front().first;
            x = q.front().second;
            q.pop();
            for(int i = 0; i < 8; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny < 0 || nx < 0 || ny >= L || nx >= L || visited[ny][nx]) continue;
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
        cout << visited[ey][ex] - 1 << "\n";
    }
}