#include<bits/stdc++.h>
using namespace std;
#define MAX 34
typedef long long ll;
ll N, dp[MAX][MAX];
ll go(int w, int h){
    if(w == 0 && h == 0) return 1;
    ll &ret = dp[w][h];
    if(ret) return ret;
    if(w) ret += go(w - 1, h + 1);
    if(h) ret += go(w, h - 1);
    return ret;
}
int main(){
    while(true){
        cin >> N;
        if(N == 0) break;
        cout << go(N, 0) << "\n";
    }
}