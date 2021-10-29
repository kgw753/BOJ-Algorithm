#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, M, K, r, c, s;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> op;
int getRes(){
    int ret = 1e9;
    for(int i = 0; i < N; i++){
        int tmp = 0;
        for(int j = 0; j < M; j++){
            tmp += MAP[i][j];
        }
        ret = min(ret, tmp);
    }
    return ret;
}
void rot(int r, int c, int s){
    vector<vector<int>> tmp(MAP);
    for(int i = c - s + 1; i <= c + s; i++){
        MAP[r - s][i] = tmp[r - s][i - 1];
    }
    for(int i = r - s + 1; i <= r + s; i++){
        MAP[i][c + s] = tmp[i - 1][c + s];
    }
    for(int i = c + s; i > c - s; i--){
        MAP[r + s][i - 1] = tmp[r + s][i];
    }
    for(int i = r + s; i > r - s; i--){
        MAP[i - 1][c - s] = tmp[i][c - s];
    }
}
int main(){
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
        }
    }
    for(int i = 0; i < K; i++){
        cin >> r >> c >> s;
        r--, c--;
        op.push_back({r, c, s});
    }
    sort(op.begin(), op.end());
    int res = 1e9;
    vector<vector<int>> tmp;
    do{
        tmp = MAP;
        for(int i = 0; i < K; i++){
            for(int j = 1; j <= op[i][2]; j++){
                rot(op[i][0], op[i][1], j);
            }
        }
        res = min(getRes(), res);
        MAP = tmp;
    }while(next_permutation(op.begin(), op.end()));
    cout << res << "\n";
}