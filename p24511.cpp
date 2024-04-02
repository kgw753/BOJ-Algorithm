#include <bits/stdc++.h>
using namespace std;
#define MAX 100004

bool isStack[MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  deque<int> dq;

  int N, M;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> isStack[i];
  }

  int input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    if (!isStack[i]) {
      dq.push_back(input);
    }
  }

  cin >> M;

  for (int i = 0; i < M; i++) {
    cin >> input;
    dq.push_front(input);
    cout << dq.back() << " ";
    dq.pop_back();
  }
}