#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
  int res = 0;
  cin >> N;
  for (int i = 1; i <= N; i *= 10) {
    res += N - i + 1;
  }
  cout << res << "\n";
}