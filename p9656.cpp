#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N;
int dp[MAX];
int main(){
	cin >> N;
	dp[1] = dp[3] = 0;
	dp[2] = 1;
	for(int i = 4; i <= N; i++){
		if(dp[i - 1] == dp[i - 3]) dp[i] = !dp[i - 1];
        else dp[i] = i % 2;
	}
	if(dp[N]) cout << "SK\n";
	else cout << "CY\n";
}