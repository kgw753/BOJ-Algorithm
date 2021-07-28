#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int R, C, T;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> tmp(MAX, vector<int>(MAX, 0));
vector<int> pos;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void clearTmp(){
    for(int i = 0; i < R; i++) fill(tmp[i].begin(), tmp[i].begin() + C, 0);
    tmp[pos[0]][0] = tmp[pos[1]][0] = -1;
}
int counter(){
    int ret = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(MAP[i][j] == -1) continue;
            ret += MAP[i][j];
        }
    }
    return ret;
}
void goClear(){
    int t, prev = 0;
    for(int i = 1; i < C; i++){
        t = MAP[pos[0]][i];
        MAP[pos[0]][i] = prev;
        prev = t;
    }
    for(int i = pos[0] - 1; i >= 0; i--){
        t = MAP[i][C - 1];
        MAP[i][C - 1] = prev;
        prev = t;
    }
    for(int i = C - 2; i >= 0; i--){
        t = MAP[0][i];
        MAP[0][i] = prev;
        prev = t;
    }
    for(int i = 1; i < pos[0]; i++){
        t = MAP[i][0];
        MAP[i][0] = prev;
        prev = t;
    }
    prev = 0;
    for(int i = 1; i < C; i++){
        t = MAP[pos[1]][i];
        MAP[pos[1]][i] = prev;
        prev = t;
    }
    for(int i = pos[1] + 1; i < R; i++){
        t = MAP[i][C - 1];
        MAP[i][C - 1] = prev;
        prev = t;
    }
    for(int i = C - 2; i >= 0; i--){
        t = MAP[R - 1][i];
        MAP[R - 1][i] = prev;
        prev = t;
    }
    for(int i = R - 2; i > pos[1]; i--){
        t = MAP[i][0];
        MAP[i][0] = prev;
        prev = t;
    }
}
void goMise(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            int cnt = 0;
            if(MAP[i][j] == 0 || MAP[i][j] == -1) continue;
            for(int k = 0; k < 4; k++){
                int nx = j + dx[k];
                int ny = i + dy[k];
                if(nx < 0 || ny < 0 || nx >= C || ny >= R || MAP[ny][nx] == -1) continue;
                cnt++;
                tmp[ny][nx] += (MAP[i][j] / 5);
            }
            tmp[i][j] += MAP[i][j] - (MAP[i][j] / 5) * cnt;
        }
    }
}
int main(){
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == -1) pos.push_back(i);
        }
    }
    while(T--){
        clearTmp();
        goMise();
        MAP = tmp;
        goClear();
    }
    cout << counter() << "\n";
}