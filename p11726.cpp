#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N;
int dp[MAX];
int go(int n){
    int &ret = dp[n];
    if(ret) return ret;
    if(n <= 2) return ret = n;
    return ret = (go(n - 1) + go(n - 2)) % 10007;
}
int main(){
    cin >> N;
    dp[1] = 1;
    cout << go(N) << "\n";
}