#include<bits/stdc++.h>
using namespace std;
#define MAX 54
int N, M, K, r, c, s, res = 1e9;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<tuple<int, int, int>> op;
int minCheck(){
    int ret = 1e9;
    for(int i = 0; i < N; i++){
        int mn = 0;
        for(int j = 0; j < M; j++){
            mn += MAP[i][j];
        }
        ret = min(ret, mn);
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
    vector<vector<int>> tmp(MAP);
    sort(op.begin(), op.end());
    do{
        for(int i = 0; i < op.size(); i++){
            r = get<0>(op[i]);
            c = get<1>(op[i]);
            s = get<2>(op[i]);
            for(int j = 0; j < s; j++){
                rot(r, c, s - j);
            }
        }
        res = min(res, minCheck());
        MAP = tmp;
    }while(next_permutation(op.begin(), op.end()));
    cout << res << "\n";
}