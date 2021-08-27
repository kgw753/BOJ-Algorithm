#include<bits/stdc++.h>
using namespace std;
#define MAX 404
int n, m, q, a, b, hist[MAX][MAX];
int main(){
    fill(&hist[0][0], &hist[0][0] + MAX * MAX, 1e9);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--, b--;
        hist[a][b] = -1;
        hist[b][a] = 1;
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(hist[i][k] == 1 && hist[k][j] == 1) hist[i][j] = 1;
                else if(hist[i][k] == -1 && hist[k][j] == -1) hist[i][j] = -1;
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        a--, b--;
        if(hist[a][b] == 1e9) cout << 0 << "\n";
        else cout << hist[a][b] << "\n";
    }
}