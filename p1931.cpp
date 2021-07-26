#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, s, e, ans;
vector<pair<int, int>> v(MAX);
bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        v[i] = make_pair(s, e);
    }
    sort(v.begin(), v.begin() + N, cmp);
    e = -1;
    for(int i = 0; i < N; i++){
        if(e <= v[i].first) e = v[i].second, ans++;
    }
    cout << ans << "\n";
}