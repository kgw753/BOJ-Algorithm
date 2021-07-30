#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, K, L, len = 1, sec = 0, x, y, dir;
char c;
bool gameOver = false;
deque<pair<int, int>> dq;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
queue<pair<int, char>> mov;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void go(){
    pair<int, int> head = dq.front();
    int nx = head.second + dx[dir];
    int ny = head.first + dy[dir];
    if(nx < 0 || ny < 0 || nx >= N || ny >= N || MAP[ny][nx] == 1){
        gameOver = true;
        return;
    }
    if(MAP[ny][nx] == 0){
        MAP[dq.back().first][dq.back().second] = 0;
        dq.pop_back();
    }
    MAP[ny][nx] = 1;
    dq.push_front({ny, nx});
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> y >> x;
        x--, y--;
        MAP[y][x] = 2;
    }
    cin >> L;
    for(int i = 0; i < L; i++){
        cin >> x >> c;
        mov.push(make_pair(x, c));
    }
    dq.push_back({0, 0});
    MAP[0][0] = 1;
    while(true){
        sec++;
        go();
        if(gameOver) break;
        if(mov.front().first == sec){
            if(mov.front().second == 'L'){
                dir = (dir - 1 + 4) % 4;
            }
            else if(mov.front().second == 'D'){
                dir = (dir + 1 + 4) % 4;
            }
            mov.pop();
        }
    }
    cout << sec << "\n";
}