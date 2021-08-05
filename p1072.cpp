#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll X, Y, Z, lo, mid, hi, ans;
bool check(ll mid){
    return (Y + mid) * 100 / (X + mid) != Z;
}
int main(){
    cin >> X >> Y;
    Z = Y * 100 / X;
    lo = 1;
    hi = 1e9;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
    }
    if(ans == 0) ans = -1;
    cout << ans << "\n";
}