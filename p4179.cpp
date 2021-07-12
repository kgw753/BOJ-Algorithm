#include<bits/stdc++.h>
using namespace std;
#define MAX 1002

vector<vector<char>> MAP(MAX, vector<char>(MAX, 'E'));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
int N, M, cnt;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<pair<int, int>> firePos, jhPos;
int ex = -1, ey = -1;

void goFire(){
    queue<pair<int, int>> tmp;
    while(!firePos.empty()){
        int x = firePos.front().second;
        int y = firePos.front().first;
        firePos.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx >= M + 1 || ny < 1 || ny >= N + 1) continue;
            if(MAP[ny][nx] == '.') {
                MAP[ny][nx] = 'F';
                tmp.push(make_pair(ny, nx));
            }
        }
    }
    firePos = tmp;
}

void goJH(){
    queue<pair<int, int>> tmp;
    while(!jhPos.empty()){
        int x = jhPos.front().second;
        int y = jhPos.front().first;
        jhPos.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= M + 2 || ny < 0 || ny >= N + 2) continue;
            if(MAP[ny][nx] == 'E'){
                ex = x;
                ey = y;
                return;
            }
            if (visited[ny][nx] == 0 && MAP[ny][nx] == '.'){
                visited[ny][nx] = visited[y][x] + 1;
                tmp.push(make_pair(ny, nx));
            }
        }
    }
    jhPos = tmp;
}

int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 'J'){
                jhPos.push(make_pair(i, j));
                visited[i][j] = 0;
            }
            else if(MAP[i][j] == 'F'){
                firePos.push(make_pair(i, j));
            }
        }
    }
    while(!jhPos.empty()){
        goFire();
        goJH();
        if(ex != -1 && ey != -1) break;
    }

    if(ex != -1 && ey != -1){
        cout << visited[ey][ex] + 1 << "\n";
    }
    else cout << "IMPOSSIBLE\n";
}