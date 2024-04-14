#include <bits/stdc++.h>
using namespace std;

const int MAX = 500001;
const int MAX_BUTTON = 10;
const int START = 100;
int N, M, ans1 = 1e9, ans2 = 1e9;
bool broken[MAX_BUTTON];

bool checkPressable(int channel) {
  if (channel == 0) {
    return !broken[0];
  }

  while (channel > 0) {
    int currButton = channel % 10;
    if (broken[currButton]) {
      return false;
    }
    channel /= 10;
  }

  return true;
}

void solve() {
  ans1 = abs(START - N);
  for (int i = 0; i < MAX; i++) {
    int goDown = N - i;
    int goUp = N + i;
    if (goDown >= 0 && checkPressable(goDown)) {
      ans2 = to_string(goDown).length() + i;
      break;
    }
    if (checkPressable(goUp)) {
      ans2 = to_string(goUp).length() + i;
      break;
    }
  }

  cout << min(ans1, ans2) << "\n";
}

void input() {
  cin >> N >> M;
  int buttonIdx;
  for (int i = 0; i < M; i++) {
    cin >> buttonIdx;
    broken[buttonIdx] = true;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
}