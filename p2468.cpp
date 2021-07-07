#include<bits/stdc++.h>
using namespace std;
#define MAX 101
int N, m, M;
int area;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<bool>> visited(MAX, vector<bool>(MAX, false));
vector<vector<bool>> counter(MAX, vector<bool>(MAX, false));

void print(vector<vector<bool>> v){
    cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void bfs(int h, int y, int x){
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[y][x] = true;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(MAP[ny][nx] == h && visited[ny][nx] == false){
                q.push(make_pair(nx, ny));
                visited[ny][nx] = true;
            }
        }
    }
}

void areaCnt(int x, int y){
    counter[y][x] = true;

    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if(counter[ny][nx] == false){
            areaCnt(nx, ny);
        }
        
    }
}

int main(){
    cin >> N;
    m = MAX;
    M = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            m = min(m, MAP[i][j]);
            M = max(M, MAP[i][j]);
        }
    }

    area = 1;
    for(int i = m; i <= M; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(MAP[j][k] == i && visited[j][k] == false){
                    bfs(i, j, k);
                }
            }
        }

        int cnt = 0;
        counter = visited;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(counter[k][j] == false){
                    areaCnt(j, k);
                    cnt++;
                }
            }
        }

        area = max(area, cnt);
    }
    cout << area << "\n";
}