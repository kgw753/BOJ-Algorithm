#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000001;
const int OFFSET = 1000000009;
int T;
long long dp[MAX];
vector<int> tc;

void fillDp() {
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  for (int i = 4; i < MAX; i++) {
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % OFFSET;
  }
}

void solve() {
  fillDp();
  for (long long num : tc) {
    cout << dp[num] << "\n";
  }
}

void input() {
  cin >> T;
  int t;
  for (int i = 0; i < T; i++) {
    cin >> t;
    tc.push_back(t);
  }
}

int main() {
  input();
  solve();
}