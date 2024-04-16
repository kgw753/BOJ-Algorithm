#include <bits/stdc++.h>
using namespace std;
int N;
vector<pair<int, int>> v;
void solve() {
  sort(v.begin(), v.end());
  priority_queue<int, vector<int>, greater<int>> pq;
  for (pair<int, int> p : v) {
    pq.push(p.second);
    if (pq.size() > p.first) {
      pq.pop();
    }
  }
  int sum = 0;
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }
  cout << sum << "\n";
}
void input() {
  cin >> N;
  int deadLine, prize;
  for (int i = 0; i < N; i++) {
    cin >> deadLine >> prize;
    v.push_back({deadLine, prize});
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
}