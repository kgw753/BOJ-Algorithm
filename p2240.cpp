#include<bits/stdc++.h>
using namespace std;
#define MAX_SEC 1004
#define MAX_MOV 34
int T, W;
int dp[MAX_SEC][MAX_MOV][2];
int v[MAX_SEC];
int go(int sec, int mov, int pos){
	if(sec > T || mov < 0) return 0;
	int &ret = dp[sec][mov][pos];
	if(~ret) return ret;
	return ret = max(go(sec + 1, mov, pos), go(sec + 1, mov - 1, !pos)) + (v[sec] == pos);
}
int main(){
	cin >> T >> W;
	for(int i = 0; i < T; i++){
		cin >> v[i];
		v[i]--;
	}
	memset(dp, -1, sizeof(dp));
	cout << max(go(0, W, 0), go(0, W - 1, 1)) << "\n";
}