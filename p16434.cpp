#include<bits/stdc++.h>
using namespace std;
#define MAX 123460
typedef long long ll;
ll N, A, H, cH, t, a, h;
ll pH, pA, mH, mA;
vector<tuple<int, int, int>> v;
void beStronger(ll a, ll h, ll mH){
    A += a;
    cH += h;
    if(cH > mH) cH = mH;
}
void monster(ll a, ll h){
    while(true){
        h -= A;
        if(h <= 0) break;
        cH -= a;
        if(cH <= 0) break;
    }
}
bool check(ll mid){
    cH = mid;
    for(int i = 0; i < N; i++){
        int t = get<0>(v[i]);
        ll a = get<1>(v[i]);
        ll h = get<2>(v[i]);
        if(t == 1){
            ll cnt = h / A + (h % A ? 1 : 0);
            cH -= (cnt - 1) * a;
        }
        else{
            A += a;
            cH = min(cH + h, mid);
        }
        if(cH <= 0) return false;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> N >> A;
    for(int i = 0; i < N; i++){
        cin >> t >> a >> h;
        v.push_back(make_tuple(t, a, h));
    }
    ll lo = 1;
    ll hi = 123456000000000000LL;
    ll mid;
    ll tmp = A;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        A = tmp;
        if(check(mid)){
            hi = mid - 1;
            H = mid;
        }
        else lo = mid + 1;
    }
    cout << H << "\n";
}