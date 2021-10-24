#include<bits/stdc++.h>
using namespace std;
#define MAX 40004
const int DIV = 123456789;
int N, che[MAX];
vector<int> prime, dp(MAX);
int main(){
    for(int i = 2; i < MAX; i++){
        if(che[i]) continue;
        prime.push_back(i);
        for(int j = i * 2; j < MAX; j += i){
            che[j] = true;
        }
    }
    cin >> N;
    dp[0] = 1;
    for(int p : prime){
        for(int i = p; i < MAX; i++){
            dp[i] = (dp[i] + dp[i - p]) % DIV;
        }
    }
    cout << dp[N] << "\n";
}