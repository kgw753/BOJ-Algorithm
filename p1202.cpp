#include <bits/stdc++.h>
using namespace std;
int N, K;
vector<pair<int, int>> gems;
vector<int> bags;

void solve() {
  sort(gems.begin(), gems.end());
  sort(bags.begin(), bags.end());

  int gemIdx = 0;
  priority_queue<int> pq;
  long sum = 0;
  for (int i = 0; i < K; i++) {
    while (gemIdx < N && gems[gemIdx].first <= bags[i]) {
      pq.push(gems[gemIdx++].second);
    }
    if (!pq.empty()) {
      sum += pq.top();
      pq.pop();
    }
  }

  cout << sum << "\n";
}

void input() {
  cin >> N >> K;
  int m, v, c;
  for (int i = 0; i < N; i++) {
    cin >> m >> v;
    gems.push_back({m, v});
  }
  for (int i = 0; i < K; i++) {
    cin >> c;
    bags.push_back(c);
  }
}

int main() {
  input();
  solve();
}