#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N, K, g, x, len;
int v[MAX];
int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> g >> x;
        v[x] = g;
    }
    K = K * 2 + 1;
    int mx = 0;
    for(int i = 0 ; i <= 1e6; i++){
        if(i >= K) len -= v[i - K];
        len += v[i];
        mx = max(mx, len);
    }
    cout << mx << "\n";
}