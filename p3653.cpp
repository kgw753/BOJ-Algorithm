#include<bits/stdc++.h>
using namespace std;
#define MAX 200004
int T, N, M, temp, tree[MAX];
map<int, int> mp;
void update(int idx, int num){
    while(idx < MAX){
        tree[idx] += num;
        idx += (idx & -idx);
    }
}
int sum(int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main(){
    fastIO();
    cin >> T;
    while(T--){
        cin >> N >> M;
        memset(tree, 0, sizeof(tree));
        mp.clear();
        int update_idx = 100001;
        for(int i = 1; i <= N; i++){
            update(i + update_idx, 1);
            mp[i] = i + update_idx;
        }
        for(int i = 0; i < M; i++){
            cin >> temp;
            int idx = mp[temp];
            cout << sum(idx) - 1 << " ";
            update(idx, -1);
            update(--update_idx, 1);
            mp[temp] = update_idx;
        }
        cout << "\n";
    }
}