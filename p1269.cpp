#include<bits/stdc++.h>
using namespace std;
int N, M, input, ans;
map<int, int> m;
int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> input;
        m[input]++;
    }
    for(int i = 0; i < M; i++){
        cin >> input;
        m[input]++;
    }
    for(pair<int, int> p: m) if(p.second == 1) ans++;
    cout << ans << "\n";
}