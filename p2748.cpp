#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll dp[94];
ll fibo(int n){
    if(n < 2) return n;
    if(dp[n]) return dp[n];
    return dp[n] = fibo(n - 1) + fibo(n - 2);
}
int main(){
    cin >> N;
    cout << fibo(N) << "\n";
}