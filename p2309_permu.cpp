#include <bits/stdc++.h>
using namespace std;
int N = 9;
vector<int> heights(N);
int main() {
  for (int i = 0; i < N; i++) {
    cin >> heights[i];
  }

  sort(heights.begin(), heights.end());

  do {
    int sum = 0;

    for (int i = 0; i < 7; i++)
      sum += heights[i];

    if (sum == 100)
      break;
  } while (next_permutation(heights.begin(), heights.end()));

  for (int i = 0; i < 7; i++)
    cout << heights[i] << "\n";
}