#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
typedef long long ll;
ll S, C, sum, len, cnt;
vector<ll> L(MAX, 0);
bool check(int mid){
    cnt = 0;
    for(int i = 0; i < S; i++){
        cnt += (L[i] / mid);
    }
    return cnt >= C;
}
int main(){
    cin >> S >> C;
    for(int i = 0; i < S; i++){
        cin >> L[i];
        sum += L[i];
    }
    ll lo = 1;
    ll hi = 1e9;
    ll mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            lo = mid + 1;
            len = mid;
        }
        else hi = mid - 1;
    }
    cout << sum - (C * len) << "\n";
}