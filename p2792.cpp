#include<bits/stdc++.h>
using namespace std;
#define MAX 300004
int N, M, lo, hi, mid, ans = 1e9;
vector<int> v(MAX, 0);
bool check(int k){
    int cnt = 0;
    for(int i = 0; i < M; i++){
        cnt += v[i] / k;
        if(v[i] % k) cnt++;
    }
    return N >= cnt;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> v[i];
        hi = max(hi, v[i]);
    }
    lo = 1;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << "\n";
}