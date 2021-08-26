#include<bits/stdc++.h>
using namespace std;
#define MAX 128
int N, MAP[MAX][MAX], cost[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<int> ans;
priority_queue<pair<int , int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(){
    while(true){
        scanf("%d", &N);
        memset(MAP, 0, sizeof(MAP));
        for(int i = 0; i < N; i++){
            fill(cost[i], cost[i] + N, 1e9);
        }
        if(N == 0) break;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d ", &MAP[i][j]);
            }
        }
        pq.push({MAP[0][0], 0});
        cost[0][0] = MAP[0][0];
        while(pq.size()){
            int c = pq.top().first;
            int x = pq.top().second % N;
            int y = pq.top().second / N;
            pq.pop();
            if(c != cost[y][x]) continue;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if(cost[ny][nx] > cost[y][x] + MAP[ny][nx]){
                    cost[ny][nx] = cost[y][x] + MAP[ny][nx];
                    pq.push({cost[ny][nx], ny * N + nx});
                }
            }
        }
        ans.push_back(cost[N - 1][N - 1]);
    }
    for(int i = 0; i < ans.size(); i++) {
        printf("Problem %d: %d\n", i + 1, ans[i]);
    }
}