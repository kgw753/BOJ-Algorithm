#include<bits/stdc++.h>
using namespace std;
#define MAX 2200
int N, MAP[MAX][MAX];
int ans[3];
int dy[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
int dx[] = {0, 0, 0, 1, 1, 1, 2, 2, 2};
void go(int y, int x, int size){
    int now = MAP[y][x];
    bool flag = true;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(MAP[i][j] != now){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag){
        if(now == -1){
            ans[0]++;
        }
        else if(now == 0){
            ans[1]++;
        }
        else if(now == 1){
            ans[2]++;
        }
        return;
    }
    for(int i = 0; i < 9; i++){
        go(y + size / 3 * dy[i], x + size / 3 * dx[i], size / 3);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    go(0, 0, N);
    for(int a : ans) cout << a << "\n";
}