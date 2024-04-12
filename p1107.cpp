#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500001;
const int MAX_M = 10;
const int START = 100;
int N, M, res;
bool notWork[MAX_M];

int getPressCount(int num) {
  if (num == 0)
    return 1;
  int cnt = 0;
  while (num > 0) {
    cnt++;
    num /= 10;
  }
  return cnt;
}

bool checkPressable(int num) {
  if (num == 0) {
    return !notWork[0];
  }

  while (num > 0) {
    int n = num % 10;
    if (notWork[n]) {
      return false;
    }
    num /= 10;
  }

  return true;
}

void solve() {
  int res = abs(START - N);
  for (int i = 0; i < MAX_N; i++) {
    if (N - i >= 0 && checkPressable(N - i)) {
      res = min(res, (int)to_string(N - i).length() + i);
      break;
    }
    if (checkPressable(N + i)) {
      res = min(res, (int)to_string(N + i).length() + i);
      break;
    }
  }
  cout << res << "\n";
}

void input() {
  cin >> N >> M;
  int idx;
  for (int i = 0; i < M; i++) {
    cin >> idx;
    notWork[idx] = true;
  }
}

int main() {
  input();
  solve();
}