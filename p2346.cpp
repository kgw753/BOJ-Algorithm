#include <bits/stdc++.h>
using namespace std;

struct Balloon {
  int idx, next;
};

int main() {
  int N, next;
  deque<Balloon> balloons;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> next;
    balloons.push_back((Balloon){i, next});
  }

  while (balloons.size()) {
    Balloon curr = balloons.front();
    cout << curr.idx << " ";
    next = curr.next;
    balloons.pop_front();

    if (next < 0) {
      while (next++ < 0) {
        balloons.push_front(balloons.back());
        balloons.pop_back();
      }
    } else if (next > 0) {
      while (--next > 0) {
        balloons.push_back(balloons.front());
        balloons.pop_front();
      }
    }
  }
}