#include<bits/stdc++.h>
using namespace std;
#define T_MAX 1004
#define MAX 8
int T, K, ans, L = 6, R = 2;
string input;
vector<vector<int>> MAP(T_MAX, vector<int>(MAX, 0));
vector<bool> visited(T_MAX, false);
void rot(int num, int dir){
    visited[num] = true;
    int idx;
    vector<int> v(8);
    int left = MAP[num][L];
    int right = MAP[num][R];
    for(int i = 0; i < 8; i++){
        idx = ((i + dir) + 8) % 8;
        v[idx] = MAP[num][i];
    }
    MAP[num] = v;
    if(num != 0 && left != MAP[num - 1][R] && visited[num - 1] == false){
        rot(num - 1, (dir == 1) ? -1 : 1);
    }
    if(num != T && right != MAP[num + 1][L] && visited[num + 1] == false){
        rot(num + 1, (dir == 1) ? -1 : 1);
    }
}
int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> input;
        for(int j = 0; j < MAX; j++){
            MAP[i][j] = input[j] - '0';
        }
    }
    cin >> K;
    int num, dir;
    for(int i = 0; i < K; i++){
        cin >> num >> dir;
        num--;
        rot(num, dir);
        fill(visited.begin(), visited.end(), false);
    }
    for(int i = 0; i < T; i++) if(MAP[i][0]) ans++;
    cout << ans << "\n";
}