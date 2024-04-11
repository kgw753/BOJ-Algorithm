#include <bits/stdc++.h>
using namespace std;
const int MAX = 1025;
int N, M, r, rr, c, cc, _map[MAX][MAX], psum[MAX][MAX];

void solve() {
  cout << psum[cc][rr] - psum[cc][r - 1] - psum[c - 1][rr] + psum[c - 1][r - 1]
       << "\n";
}

void inputQuestion() { cin >> c >> r >> cc >> rr; }

void fillPsum() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      psum[i][j] =
          psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + _map[i][j];
    }
  }
}

void input() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> _map[i][j];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  fillPsum();

  for (int i = 0; i < M; i++) {
    inputQuestion();
    solve();
  }
}