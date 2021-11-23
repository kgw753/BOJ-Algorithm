#include<bits/stdc++.h>
using namespace std;
#define MAX 204
int N;
vector<int> v(MAX), dp(MAX);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    int mxCnt = 0;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < i; j++){
            if(v[j] < v[i] && cnt < dp[j]) cnt = dp[j];
        }
        dp[i] = cnt + 1;
        mxCnt = max(dp[i], mxCnt);
    }
    cout << N - mxCnt << "\n";
}