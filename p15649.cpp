#include<bits/stdc++.h>
using namespace std;
int N, M;

void dfs(int k, vector<int> v){
    v.push_back(k);
    if(v.size() == M){
        for(int i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= N; i++){
        if(find(v.begin(), v.end(), i) == v.end()) dfs(i, v);
    }
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        dfs(i, vector<int>());
    }
}