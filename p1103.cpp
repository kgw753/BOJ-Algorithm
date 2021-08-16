#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, M, dp[MAX][MAX], visited[MAX][MAX];
string input;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int go(int y, int x){
    if(y < 0 || y >= N || x < 0 || x >= M || MAP[y][x] == -1) return 0;
    if(visited[y][x]){
        cout << -1 << "\n";
        exit(0);
    }
    int &ret = dp[y][x];
    if(ret) return ret;
    visited[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + (dx[i] * MAP[y][x]);
        int ny = y + (dy[i] * MAP[y][x]);
        ret = max(ret, go(ny, nx) + 1);
    }
    visited[y][x] = 0;
    return ret;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            if(input[j] == 'H') MAP[i][j] = -1;
            else MAP[i][j] = input[j] - '0';
        }
    }
    cout << go(0, 0) << "\n";
}