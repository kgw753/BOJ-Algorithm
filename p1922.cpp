#include <bits/stdc++.h>
using namespace std;
const int MAX = 1004;
int N, M, a, b, c, rootIdx[MAX], res;

vector<pair<int, pair<int, int>>> v;

void input() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;
    v.push_back({c, {a, b}});
  }
}

int getRoot(int idx) {
  if (rootIdx[idx] == idx)
    return idx;
  else
    return rootIdx[idx] = getRoot(rootIdx[idx]);
}

void unionTree(int from, int to) {
  from = getRoot(from);
  to = getRoot(to);

  if (from != to)
    rootIdx[to] = from;
}

bool isSameRoot(int from, int to) { return getRoot(from) == getRoot(to); }

void solve() {
  sort(v.begin(), v.end());

  for (int i = 1; i <= N; i++) {
    rootIdx[i] = i;
  }

  for (int i = 0; i < M; i++) {
    int from = v[i].second.first;
    int to = v[i].second.second;
    int cost = v[i].first;

    if (!isSameRoot(from, to)) {
      unionTree(from, to);
      res += cost;
    }
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
}