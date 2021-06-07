#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    vector<vector<long long>> dp(65, vector<long long>(10, 0));
    vector<long long> answer;

    for(int i = 0; i < 10; i++){
        dp[1][i] = 1;
    }

    for(int i = 1; i < 65; i++){
        dp[i][9] = 1;
    }

    for(int i = 2; i < 65; i++){
        for(int j = 8; j > -1; j--){
            dp[i][j] = dp[i - 1][j] + dp[i][j + 1];
        }
    }

    for(int i = 0; i < T; i++){
        int N;
        cin >> N;
        long long ans = 0;
        for(int i = 0; i < 10; i++){
            ans += dp[N][i];
        }
        answer.push_back(ans);
    }

    for(auto ans: answer){
        cout << ans << "\n";
    }
}