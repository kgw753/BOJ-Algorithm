#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, M, lo = 1e9, hi, mid, ans = 1e9;
vector<int> v(MAX, 0);
bool check(int mid){
    for(int i = 0; i < N; i++){
        if(v[i] > mid) return false;
    }
    int cnt = 1, tmp = mid;
    for(int i = 0; i < N; i++){
        if(mid - v[i] < 0){
            mid = tmp;
            cnt++;
        }
        mid -= v[i];
    }
    return M >= cnt;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        lo = min(lo, v[i]);
        hi += v[i];
    }
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            hi = mid - 1;
            ans = mid;
        }
        else lo = mid + 1;
    }
    cout << ans << "\n";
}