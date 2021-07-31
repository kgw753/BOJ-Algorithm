#include<bits/stdc++.h>
using namespace std;
int N, M;
void dfs(vector<int> v, int k){
    v.push_back(k);
    if(v.size() == M){
        for(int i : v) cout << i << " ";
        cout << "\n";
        return;
    }
    for(int i = k; i <= N; i++){
        dfs(v, i);
    }
}
int main(){
    cin >> N >> M;
    for(int i = 1; i <= N; i++){

        dfs(vector<int>(), i);
    }
}