#include<bits/stdc++.h>
using namespace std;

int X, ans = 1;

void dfs(int stick, int sum){
    if(sum == X) return;
    int newStick = stick / 2;
    if(sum - newStick >= X) sum -= newStick;
    else ans++;
    dfs(newStick, sum);
}

int main(){
    cin >> X;
    int start = 64;
    dfs(start, start);
    cout << ans << "\n";
}