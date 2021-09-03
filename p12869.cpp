#include<bits/stdc++.h>
using namespace std;
int N, scv[3], cnt = 1e9;
bool allDie(){
    for(int i = 0; i < N; i++){
        if(scv[i] > 0) return false;
    }
    return true;
}
void attack(int depth, vector<int> dmg){
    if(allDie()){
        cnt = min(cnt, depth);
        return;
    }
    do{
        for(int i = 0; i < 3; i++) scv[i] -= dmg[i];
        attack(depth + 1, dmg);
        for(int i = 0; i < 3; i++) scv[i] += dmg[i];
    }while(next_permutation(dmg.begin(), dmg.end()));
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> scv[i];
    attack(0, {1, 3, 9});
    cout << cnt << "\n";
}