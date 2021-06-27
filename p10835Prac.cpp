#include<bits/stdc++.h>
using namespace std;
#define MAX 2001

int N;
vector<int> Left;
vector<int> Right;
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));
vector<vector<int>> visited(MAX, vector<int>(MAX, false));


int dfs(int l, int r){
    if(visited[l][r]){
        return dp[l][r];
    }
    visited[l][r] = true;
    
    if(l == N || r == N){
        return 0;
    }

    if(Right[r] < Left[l]){
        dp[l][r] = dfs(l, r + 1) + Right[r];
    }
    else{
        dp[l][r] = max(dfs(l + 1, r), dfs(l + 1, r + 1));
    }
    return dp[l][r];
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int l;
        cin >> l;
        Left.push_back(l);
    }

    for(int i = 0; i < N; i++){
        int r;
        cin >> r;
        Right.push_back(r);
    }

    cout << dfs(0, 0) << "\n";
}