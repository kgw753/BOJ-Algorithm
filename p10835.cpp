#include<bits/stdc++.h>
using namespace std;
#define MAX 2001
int N;
vector<int> A;
vector<int> B;
vector<vector<int>> dp(MAX, vector<int>(MAX, -1));
int score = -1;

int calc(int a, int b){
    if(dp[a][b] != -1) return dp[a][b];
    if(N == a || N == b) return 0;

    if(A[a] <= B[b]) {
        dp[a][b] = max(calc(a + 1, b), calc(a + 1, b + 1));
    }
    else {
        dp[a][b] = calc(a, b + 1) + B[b];
    }

    return dp[a][b];
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        A.push_back(input);
    }

    for(int i = 0; i < N; i++){
        int input;
        cin >> input;
        B.push_back(input);
    }

    
    cout << calc(0, 0) << "\n";
}