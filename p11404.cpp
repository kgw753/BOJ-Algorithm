#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, M, a, b, c;
int dist[104][104];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    fill(&dist[0][0], &dist[0][0] + MAX * MAX, 1e9);
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = min(dist[a][b], c);
    }
    for(int k = 0; k < N; k++)
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist[i][j] == 1e9 || i == j) cout << 0 << " ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}