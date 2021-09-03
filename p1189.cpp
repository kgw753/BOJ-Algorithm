#include<bits/stdc++.h>
using namespace std;
#define MAX 7
int N, M, K, cnt, visited[MAX][MAX];
char MAP[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string input;
int go(int y, int x, int dist){
    if(dist == K){
        if(y == 0 && x == M - 1) return 1;
        else return 0;
    }
    int ret = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || visited[ny][nx] || MAP[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        ret += go(ny, nx, dist + 1);
        visited[ny][nx] = 0;
    }
    return ret;
}
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
        }
    }
    visited[N - 1][0] = 1;
    cout << go(N - 1, 0, 1) << "\n";
}