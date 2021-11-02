#include<bits/stdc++.h>
using namespace std;
#define MAX 17
int N;
int T[MAX], P[MAX];
int dp[MAX];
int go(int day){
	if(day == N) return 0;
	if(day > N) return -1e9;
	int &ret = dp[day];
	if(ret) return ret;
	return ret = max(go(day + 1), go(day + T[day]) + P[day]);
}
int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> T[i] >> P[i];
	}
	cout << go(0) << "\n";
}