#include<bits/stdc++.h>
using namespace std;
#define MAX 11
int N, M, K, x, y, z, res;
int MAP[MAX][MAX], s2[MAX][MAX];
vector<int> tree[MAX][MAX];
int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
void FW(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(tree[i][j].empty()) continue;
            for(int t: tree[i][j]){
                if(t % 5) continue;
                for(int k = 0; k < 8; k++){
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
                    tree[ny][nx].push_back(1);
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            MAP[i][j] += s2[i][j];
        }
    }
}
void SS(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            sort(tree[i][j].begin(), tree[i][j].end());
            vector<int> tmp;
            int deadTree = 0;
            for(int t: tree[i][j]){
                if(t <= MAP[i][j]){
                    MAP[i][j] -= t;
                    tmp.push_back(t + 1);
                }
                else {
                    deadTree += (t / 2);
                }
            }
            tree[i][j].clear();
            tree[i][j] = tmp;
            MAP[i][j] += deadTree;
        }
    }
}
void mapSet(){
    for(int i = 0; i < MAX; i++){
        fill(MAP[i], MAP[i] + MAX, 5);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> s2[j][i];
        }
    }
    mapSet();
    for(int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        tree[y - 1][x - 1].push_back(z);
    }
    for(int i = 0; i < K; i++){
        SS();
        FW();
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            res += tree[i][j].size();
        }
    }
    cout << res << "\n";
}