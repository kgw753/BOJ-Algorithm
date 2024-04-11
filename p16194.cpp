#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int N, cost[MAX], dp[MAX];

void fillDp() {
  for (int i = 1; i <= N; i++) {
    dp[i] = cost[i];

    for (int j = 1; j <= i / 2; j++) {
      dp[i] = min(dp[i], dp[j] + dp[i - j]);
    }
  }
}

void solve() {
  fillDp();
  cout << dp[N] << "\n";
}

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> cost[i];
  }
}

int main() {
  input();
  solve();
}