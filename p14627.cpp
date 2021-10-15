#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
typedef long long ll;
ll S, C, hi, lo, mid, len;
vector<ll> L(MAX);
bool check(ll mid){
    ll cnt = 0;
    for(ll i = 0; i < S; i++){
        cnt += (L[i] / mid);
    }
    return cnt >= C;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> S >> C;
    ll sum = 0;
    for(ll i = 0; i < S; i++){
        cin >> L[i];
        sum += L[i];
    }
    hi = 1e9;
    lo = 1;
    while(lo <= hi){
        mid = (hi + lo) / 2;
        if(check(mid)){
            lo = mid + 1;
            len = max(len, mid);
        }
        else {
            hi = mid - 1;
        }
    }
    cout << sum - len * C << "\n";
}