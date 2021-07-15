#include<bits/stdc++.h>
using namespace std;
#define MAX 300

int N, M, cnt;
int tx, ty, rx, ry;
string input;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
queue<pair<int, int>> q;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void jump(){
    queue<pair<int, int>> tmp;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx]) continue;
            visited[ny][nx] = cnt;
            if(MAP[ny][nx] == '0') q.push(make_pair(ny, nx));
            else tmp.push(make_pair(ny, nx));
        }
    }
    q = tmp;
    while(!tmp.empty()){
        int y = tmp.front().first;
        int x = tmp.front().second;
        tmp.pop();
        MAP[y][x] = '0';
    }
}

int main(){
    cin >> N >> M;
    cin >> ty >> tx >> ry >> rx;
    ty--, tx--, ry--, rx--;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
        }
    }

    q.push(make_pair(ty, tx));
    while(visited[ry][rx] == 0){
        cnt++;
        jump();
    }
    cout << visited[ry][rx] << "\n";   
}