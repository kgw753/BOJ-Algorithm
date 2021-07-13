#include<bits/stdc++.h>
using namespace std;
#define MAX 20
int N, M, ans;
string input;
vector<vector<char>> MAP(MAX, vector<char>(MAX));
vector<int> check('Z' - 'A' + 1, 0);
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int y, int x, int depth){
    ans = max(ans, depth);
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= M || ny >= N || check[MAP[ny][nx] - 'A']) continue;
        check[MAP[ny][nx] - 'A'] = 1;
        dfs(ny, nx, depth + 1);
        check[MAP[ny][nx] - 'A'] = 0;
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            MAP[i][j] = input[j];
        }
    }
    check[MAP[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ans << "\n";
}