#include <bits/stdc++.h>
using namespace std;
const int MAX = 100001;
const int ROW = 2;
int TC, N, _map[ROW][MAX], dp[ROW][MAX];

void solve() {
  fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int), 0);
  dp[0][0] = dp[1][0] = 0;
  dp[0][1] = _map[0][1];
  dp[1][1] = _map[1][1];

  for (int i = 2; i <= N; i++) {
    dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + _map[0][i];
    dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + _map[1][i];
  }

  cout << max(dp[0][N], dp[1][N]) << "\n";
}

void input() {
  cin >> N;
  for (int i = 0; i < ROW; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> _map[i][j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> TC;
  for (int i = 0; i < TC; i++) {
    input();
    solve();
  }
}