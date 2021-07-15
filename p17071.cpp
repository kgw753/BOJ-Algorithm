#include<bits/stdc++.h>
using namespace std;
#define MAX 500001
int N, K, ans, turn = 1;

int dx[] = {1, -1, 0};
int ddx[] = {1, 1, 2};

vector<vector<int>> visited(2, vector<int>(MAX, 0));

void bfs(){
    queue<int> q;
    q.push(N);
    if(N == K) return;
    visited[0][N] = 1;
    while(!q.empty()){
        K += turn;
        if(K >= MAX){
            ans = -1;
            break;
        }

        if(visited[turn % 2][K]){
            ans = turn;
            return;
        }
        int size = q.size();
        for(int i = 0; i < size; i++){
            N = q.front();
            q.pop();
            for (int j = 0; j < 3; j++){
                int nN = (N + dx[j]) * ddx[j];
                if (nN < 0 || nN >= MAX || visited[turn % 2][nN]) continue;
                visited[turn % 2][nN] = visited[(turn + 1) % 2][N] + 1; // Àß ÀÌÇØ ÇØ ºÁ!
                if (nN == K){
                    ans = turn;
                    return;
                }
                q.push(nN);
            }
        }
        turn++;
    }

}
int main(){
    cin >> N >> K;
    bfs();
    cout << ans << "\n";
}