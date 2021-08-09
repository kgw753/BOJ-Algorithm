#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
#define n_MAX 2000000004LL
typedef long long ll;
ll N, M, lo, mid, hi, tmp, ret;
vector<ll> v(MAX, 0);
bool check(ll mid){
    tmp = M;
    for(ll i = 0; i < M; i++) tmp += mid / v[i];
    return tmp >= N;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> v[i];
    }
    if(N <= M){
        cout << N << "\n";
        return 0;
    }
    hi = n_MAX * (ll)30;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ret = mid;
        }
        else lo = mid + 1;
    }
    tmp = M;
    for(int i = 0; i < M; i++){
        tmp += (ret - 1) / v[i];
    }
    for(int i = 0; i < M; i++){
        if(ret % v[i] == 0) tmp++;
        if(tmp == N){
            cout << i + 1 << "\n";
            return 0;
        }
    }
}