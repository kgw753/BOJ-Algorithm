#include <bits/stdc++.h>
using namespace std;
const int TOTAL_LINES = 6;
int N, M;
vector<pair<int, int>> cost;

void solve() {
  int res = 0;
  int packageCost = 1e9, eachCost = 1e9;
  for (pair<int, int> c : cost) {
    packageCost = min(packageCost, c.first);
    eachCost = min(eachCost, c.second);
  }
  packageCost = min(packageCost, eachCost * TOTAL_LINES);

  res += (N / TOTAL_LINES) * packageCost;

  res += (packageCost > N % TOTAL_LINES * eachCost)
             ? (N % TOTAL_LINES) * eachCost
             : packageCost;

  cout << res << "\n";
}

void input() {
  cin >> N >> M;
  int packageCost, eachCost;
  for (int i = 0; i < M; i++) {
    cin >> packageCost >> eachCost;
    cost.push_back({packageCost, eachCost});
  }
}

int main() {
  input();
  solve();
}