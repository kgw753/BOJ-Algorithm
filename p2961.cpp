#include<bits/stdc++.h>
using namespace std;
#define MAX 14
int N;
vector<pair<int, int>> foods(MAX);
int calc(int bm, char c){
    int ret;
    if(c == '+') ret = 0;
    else if(c == '*') ret = 1;
    for(int i = 0; i < N; i++){
        if((1 << i) & bm){
            if(c == '+') ret += foods[i].second;
            else if(c == '*') ret *= foods[i].first;
        }
    }
    return ret;
}
int main(){
    cin >> N;
    int res = 1e9;
    for(int i = 0; i < N; i++){
        cin >> foods[i].first >> foods[i].second;
    }
    for(int i = 1; i < (1 << N); i++){
        int r1 = calc(i, '+');
        int r2 = calc(i, '*');
        res = min(res, abs(r1 - r2));
    }
    cout << res << "\n";
}