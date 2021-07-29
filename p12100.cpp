#include<bits/stdc++.h>
using namespace std;
#define MAX 22
int N, ans;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
void rot90(vector<vector<int>> & v){
    vector<vector<int>> tmp(v);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp[j][(N - 1) - i] = v[i][j];
        }
    }
    v = tmp;
}
void dfs(int depth, vector<vector<int>> map){
    if(depth == 5) return;
    for(int i = 0; i < N; i++){
        vector<int> v;
        queue<int> q;
        for(int j = 0; j < N; j++){
            if(map[i][j] == 0) continue;
            q.push(map[i][j]);
        }
        int prev = 0;
        while(q.size()){
            if(prev != 0 && prev == q.front()) {
                ans = max(ans, prev * 2);
                v.pop_back();
                v.push_back(prev * 2);
                prev = 0;
            }
            else{
                v.push_back(q.front());
                prev = q.front();
            }
            q.pop();
        }
        while(v.size() < N){
            v.push_back(0);
        }
        map[i] = v;
    }
    for(int i = 0; i < 4; i++){
        dfs(depth + 1, map);
        rot90(map);
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            ans = max(ans, MAP[i][j]);
        }
    }
    for(int i = 0; i < 4; i++){
        dfs(0, MAP);
        rot90(MAP);
    }
    cout << ans << "\n";
}