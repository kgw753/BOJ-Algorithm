#include<bits/stdc++.h>
using namespace std;
#define MAX 2004
int N, M, S, E, dp[MAX][MAX];
vector<int> v(MAX, 0), ans;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++) dp[i][i] = 1;
    for(int i = 0; i < N - 1; i++) 
        if(v[i] == v[i + 1]) dp[i][i + 1] = 1;
    for(int i = 2; i < N; i++){
        for(int j = 0; j < N - i; j++){
            if(v[j] == v[i + j] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
        }
    }
    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> S >> E;
        ans.push_back(dp[S - 1][E - 1]);
    }
    for(int i : ans) cout << i << "\n";
}