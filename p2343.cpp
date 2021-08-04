#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, M, lo, mid, hi, ans;
vector<int> v(MAX, 0);
bool check(int mid){
    for(int i = 0; i < N; i++){
        if(v[i] > mid) return false;
    }
    int tmp = mid, cnt = 0;
    for(int i = 0; i < N; i++){
        if(mid - v[i] < 0){
            mid = tmp;
            cnt++;
        }
        mid -= v[i];
    }
    if(mid != tmp) cnt++;
    return M >= cnt;
}
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        hi += v[i];
    }
    lo = 0;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    cout << ans << "\n";
}