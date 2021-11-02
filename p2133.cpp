#include<bits/stdc++.h>
using namespace std;
#define MAX 34
int N;
int dp[MAX];
int main(){
	cin >> N;
	dp[2] = 3;
	for(int i = 4; i <= N; i += 2){
		dp[i] = dp[i - 2] + 2;
		for(int j = 2; j <= i - 2; j += 2){
			dp[i] += dp[j] * 2;
		}
	}
	cout << dp[N] << "\n";
}