#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> rope;
    for(int i = 0; i < N; i++){
        int weight;
        cin >> weight;
        rope.push_back(weight);
    }

    sort(rope.begin(), rope.end());

    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, rope[i] * (N - i));
    }

    cout << ans << "\n";
}