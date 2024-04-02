#include <bits/stdc++.h>
using namespace std;

deque<int> dq;

void pushFront(int num) { dq.push_front(num); }
void pushBack(int num) { dq.push_back(num); }
int popFront() {
  if (dq.empty()) {
    return -1;
  }
  int front = dq.front();
  dq.pop_front();
  return front;
}
int popBack() {
  if (dq.empty()) {
    return -1;
  }
  int back = dq.back();
  dq.pop_back();
  return back;
}
void printFront() {
  if (dq.empty())
    cout << -1 << "\n";
  else
    cout << dq.front() << "\n";
}
void printBack() {
  if (dq.empty())
    cout << -1 << "\n";
  else
    cout << dq.back() << "\n";
}
bool isEmpty() { return dq.empty(); }
int size() { return dq.size(); }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;

  int command;
  for (int i = 0; i < N; i++) {
    cin >> command;

    switch (command) {
    case 1:
      int x;
      cin >> x;
      pushFront(x);
      break;
    case 2:
      int y;
      cin >> y;
      pushBack(y);
      break;
    case 3:
      cout << popFront() << "\n";
      break;
    case 4:
      cout << popBack() << "\n";
      break;
    case 5:
      cout << size() << "\n";
      break;
    case 6:
      if (isEmpty())
        cout << 1 << "\n";
      else
        cout << 0 << "\n";
      break;
    case 7:
      printFront();
      break;
    case 8:
      printBack();
    }
  }
}