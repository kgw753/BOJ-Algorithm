#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    int max = 41;
    vector<vector<int>> dp(max, vector<int>(2, 0));
    vector<int> numbers;
    cin >> T;

    dp[0][0] = 1;
    dp[1][1] = 1;

    for(int i = 2; i < max; i++){
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    
    for(int i = 0; i < T; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }

    for(int i = 0; i < numbers.size(); i++){
        cout << dp[numbers[i]][0] << " " << dp[numbers[i]][1] << "\n";
    }
}