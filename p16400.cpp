#include<bits/stdc++.h>
using namespace std;
#define MAX 40001
int N, dp[MAX];
bool che[MAX];
vector<int> prime;
int main(){
    for(int i = 2; i < MAX; i++){
        if(che[i]) continue;
        prime.push_back(i);
        for(int j = i * 2; j < MAX; j += i){
            che[j] = true;
        }
    }
    dp[0] = 1;
    for(int p : prime){
        for(int i = p; i < MAX; i++){
            dp[i] += dp[i - p];
            dp[i] %= 123456789;
        }
    }
    cin >> N;
    cout << dp[N] << "\n";
}