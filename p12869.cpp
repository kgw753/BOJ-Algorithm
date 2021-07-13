#include<bits/stdc++.h>
using namespace std;
#define MAX 3
int N, ans = 1e9;
vector<int> scv(MAX, 0);

bool allDie(){
    for(int i = 0; i < scv.size(); i++) 
        if(scv[i] > 0) return false;
    return true;
}

void dfs(int depth, vector<int> dmg){
    if(allDie()){
        ans = min(ans, depth);
        return;
    }
    do{
        for(int i = 0; i < 3; i++) scv[i] -= dmg[i];
        dfs(depth + 1, dmg);
        for(int i = 0; i < 3; i++) scv[i] += dmg[i];
    }while(next_permutation(dmg.begin(), dmg.end()));
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> scv[i];
    }
    vector<int> dmg;
    for(int i = 1; i <= 9; i *= 3) dmg.push_back(i);
    dfs(0, dmg);
    cout << ans << "\n";
}