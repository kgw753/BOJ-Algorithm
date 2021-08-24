#include<bits/stdc++.h>
using namespace std;
#define MAX 2504
string input;
int L, dp[MAX][MAX], dp2[MAX];
int go(int idx){
    if(idx == L) return 0;
    int &ret = dp2[idx];
    if(ret != 1e9) return ret;
    for(int i = idx; i < L; i++){
        if(dp[idx][i]) ret = min(ret, go(i + 1) + 1);
    }
    return ret;
}
int main(){
    cin >> input;
    L = input.length();
    for(int i = 0; i < L; i++) dp[i][i] = 1;
    for(int i = 0; i < L - 1; i++) if(input[i] == input[i + 1]) dp[i][i + 1] = 1;
    for(int size = 2; size < L; size++){
        for(int i = 0; i < L - size; i++){
            if(input[i] == input[i + size] && dp[i + 1][i + size - 1]){
                dp[i][i + size] = 1;
            }
        }
    }
    fill(dp2, dp2 + MAX, 1e9);
    cout << go(0) << "\n";
}