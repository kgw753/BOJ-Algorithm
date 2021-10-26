#include<bits/stdc++.h>
using namespace std;
#define MAX 54

int N, M, C, r, c, s;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> op;
int getRes(){
    int ret = 1e9;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < M; j++){
            sum += MAP[i][j];
        }
        ret = min(ret, sum);
    }
    return ret;
}
void rot(int r, int c, int s){
    vector<vector<int>> tmp(MAP);
    for(int i = c - s; i < c + s; i++){
        tmp[r - s][i + 1] = MAP[r - s][i];
    }
    for(int i = r - s; i < r + s; i++){
        tmp[i + 1][c + s] = MAP[i][c + s];
    }
    for(int i = c + s; i > c - s; i--){
        tmp[r + s][i - 1] = MAP[r + s][i];
    }
    for(int i = r + s; i > r - s; i--){
        tmp[i - 1][c - s] = MAP[i][c - s];
    }
    MAP = tmp;
}
int main(){
    cin >> N >> M >> C;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
    for(int i = 0; i < C; i++){
        cin >> r >> c >> s;
        r--, c--;
        op.push_back({r, c, s});
    }
    sort(op.begin(), op.end());
    int res = 1e9;
    do{
        vector<vector<int>> tmp(MAP);
        for(int i = 0; i < op.size(); i++){
            r = op[i][0];
            c = op[i][1];
            s = op[i][2];
            for(int j = 0; j <= s; j++){
                rot(r, c, j);
            }
        }
        res = min(res, getRes());
        MAP = tmp;
    }while(next_permutation(op.begin(), op.end()));
    cout << res << "\n";
}