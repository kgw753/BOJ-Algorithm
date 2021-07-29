#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, L, a, b, r, ans, cnt;
vector<pair<int, int>> v(MAX);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.begin() + N);
    for(int i = 0; i < N; i++){
        if(r >= v[i].second) continue;
        if(v[i].first > r){
            cnt = (v[i].second - v[i].first) / L;
            if((v[i].second - v[i].first) % L) cnt += 1;
            r = v[i].first + L * cnt;
        }
        else{
            cnt = (v[i].second - r) / L;
            if((v[i].second - r) % L) cnt += 1;
            r = r + L * cnt;
        }
        ans += cnt;
    }
    cout << ans << "\n";
}