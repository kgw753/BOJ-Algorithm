#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    vector<int> coins(N, 0);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }

    int cnt = 0;
    for(int i = N - 1; i > -1; i--){
        while(K >= coins[i]){
            K -= coins[i];
            cnt++;
        }
    }
    cout << cnt << "\n";
}