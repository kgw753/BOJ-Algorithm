#include<bits/stdc++.h>
using namespace std;
int N, a, b, ans;
vector<pair<int, int>> v;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    ans = v[0].first + v[0].second;
    for(int i = 1; i < N; i++){
        ans = max(ans, v[i].first);
        ans += v[i].second;
    }
    cout << ans << "\n";
}