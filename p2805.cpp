#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
typedef long long ll;
ll N, M, hi, lo, mid;
vector<int> v(MAX);
bool check(int k){
    ll sum = 0;
    for(int i = 0; i < N; i++){
        if(v[i] - k > 0) sum += v[i] - k;
    }
    return M <= sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    lo = 0, hi = INT_MAX;
    ll ans = -1;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            lo = mid + 1;
            ans = max(ans, mid);
        }
        else hi = mid - 1;
    }
    cout << ans << "\n";
}