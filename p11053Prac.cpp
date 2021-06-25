#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> arr;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    int answer = -1;
    vector<int> dp(N, 0);

    for(int i = 0; i < N; i++){
        dp[i] = 1;

        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        answer = max(answer, dp[i]);
    }

    cout << answer << "\n";
}