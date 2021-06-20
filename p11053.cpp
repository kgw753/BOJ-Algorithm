#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> numbers;

int main(){
    cin >> N;
    vector<int> dp(N, 0);
    for(int i = 0; i < N; i++){
        int n;
        cin >> n;
        numbers.push_back(n);
    }
    
    int answer = -1;
    for(int i = 0; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(numbers[i] > numbers[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer << "\n";
}