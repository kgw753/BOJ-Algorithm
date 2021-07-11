#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int N, input, cnt;
vector<vector<int>> v(MAX, vector<int>());
vector<bool> visited(MAX, false);

void dfs(int idx){
    if(visited[idx]) return;
    visited[idx] = true;
    if(v[idx].size() == 0) cnt++;
    for(int i = 0; i < v[idx].size(); i++){
        dfs(v[idx][i]);
    }
}

void clearing(int idx){
    for(int i = 0; i < v[idx].size(); i++){
        clearing(v[idx][i]);
    }
    v[idx].clear();
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        if(input == -1) continue;
        v[input].push_back(i);
    }

    cin >> input;
    clearing(input);
    for(int i = 0; i < N; i++){
        auto del = find(v[i].begin(), v[i].end(), input);
        if(del != v[i].end()) v[i].erase(del);
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < v[i].size(); j++){
            dfs(v[i][j]);
        }
    }

    if(N == 2) cnt = 1;
    cout << cnt << "\n";
}