#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, M;
int lo, hi, mid;
vector<int> v(MAX);
bool check(int mid){
    int tot = 0;
    for(int i = 0; i < N; i++){
        tot += min(mid, v[i]);
    }
    return tot <= M;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        hi = max(hi, v[i]);
    }
    cin >> M;
    int res;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(check(mid)){
            res = mid;
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << res << "\n";
}