#include<bits/stdc++.h>
using namespace std;
#define MAX 16
int N, ans = 1e9;
int mp, mf, ms, mv;
struct A{
    int mp, mf, ms, mv, cost;
}arr[MAX];

map<int, vector<vector<int>>> res;

int main(){
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0 ; i < N; i++){
        cin >> arr[i].mp >> arr[i].mf >> arr[i].ms >> arr[i].mv >> arr[i].cost;
    }

    for(int i = 1; i < (1 << N); i++){
        vector<int> idx;
        int p, f, s, v, c;
        p = f = s = v = c = 0;
        for(int j = 0; j < N; j++){
            if(i & (1 << j)){
                idx.push_back(j + 1);
                p += arr[j].mp;
                f += arr[j].mf;
                s += arr[j].ms;
                v += arr[j].mv;
                c += arr[j].cost;
            }
        }

        if(p >= mp && f >= mf && s >= ms && v >= mv){
            if(ans >= c){
                ans = c;
                res[c].push_back(idx);
            }
        }
    }
    if(ans == 1e9) cout << -1 << "\n";
    else{
        cout << ans << "\n";
        sort(res[ans].begin(), res[ans].end());
        for(int i = 0; i < res[ans][0].size(); i++){
            cout << res[ans][0][i] << " ";
        }
        cout << "\n";
    }
}