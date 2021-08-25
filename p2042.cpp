#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
typedef long long ll;
ll N, M, K, n, a, b, c;
vector<ll> tree(MAX, 0), v(MAX, 0);
ll sum(ll idx){
    ll ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & - idx);
    }
    return ret;
}
void update(ll idx, ll num){
    while(idx < N + 1){
        tree[idx] += num;
        idx += (idx & - idx);
    }
}
int main(){
    cin >> N >> M >> K;
    for(ll i = 1; i <= N; i++){
        cin >> v[i];
        update(i, v[i]);
    }
    for(ll i = 0; i < M + K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            ll diff = c - v[b];
            v[b] = c;
            update(b, diff);
        }
        else if(a == 2){
            cout << sum(c) - sum(b - 1) << "\n";
        }
    }
}