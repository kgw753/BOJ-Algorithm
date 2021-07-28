#include<bits/stdc++.h>
using namespace std;
#define MAX 22
int N, ans = 1e9;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    for(int i = 0; i < (1 << N); i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)) cnt++;
        }
        if(cnt != N / 2) continue;
        vector<int> team1, team2;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)) team1.push_back(j);
            else team2.push_back(j);
        }
        int t1 = 0, t2 = 0;
        for(int p = 0; p < (N / 2); p++){
            for(int q = 0; q < (N / 2); q++){
                if(p == q) continue;
                t1 += MAP[team1[p]][team1[q]];
                t2 += MAP[team2[p]][team2[q]];
            }
        }
        ans = min(ans, abs(t1 - t2));
    }
    cout << ans << "\n";
}