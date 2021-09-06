#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, K, ans;
vector<int> v(MAX, 0), dist(MAX, 0);
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.begin() + N);
    for(int i = 0; i < N - 1; i++) dist[i] = v[i + 1] - v[i];
    sort(dist.begin(), dist.begin() + (N - 1));
    for(int i = 0; i < N - 1 - (K - 1); i++) ans += dist[i];
    cout << ans << "\n";
}