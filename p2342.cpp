#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
vector<int> v;
int l, r, cnt, input, dp[5][5][MAX];
int check(int from, int to){
    if(from == to) return 1;
    if(from == 0) return 2;
    if(abs(from - to) == 2) return 4;
    return 3;
}
int go(int l, int r, int idx){
    if(idx == cnt) return 0;
    int &ret = dp[l][r][idx];
    if(ret) return ret;
    ret = 1e9;
    ret = min(ret, go(v[idx], r, idx + 1) + check(l, v[idx]));
    ret = min(ret, go(l, v[idx], idx + 1) + check(r, v[idx]));
    return ret;
}
int main(){
    for(int i = 0; i < MAX; i++){
        cin >> input;
        if(input == 0) break;
        v.push_back(input);
    }
    cnt = v.size();
    cout << go(0, 0, 0) << "\n";
}