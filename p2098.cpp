#include<bits/stdc++.h>
using namespace std;
#define MAX 16
int N;
int dp[MAX][1 << MAX];
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
int go(int here, int visited){
    if(visited == (1 << N) - 1) return MAP[here][0] ? MAP[here][0] : 1e9;
    int &ret = dp[here][visited];
    if(~ret) return ret;
    ret = 1e9;
    for(int i = 0; i < N; i++){
        if((1 << i) & visited) continue;
        if(MAP[here][i] == 0) continue;
        ret = min(ret, go(i, visited | (1 << i)) + MAP[here][i]);
    }
    return ret;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, 1) << "\n";
}