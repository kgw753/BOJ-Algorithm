#include <bits/stdc++.h>
using namespace std;
int N = 9;
vector<int> heights(N);

void permutation(int n, int r, int depth) {
  if (depth == r) {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
      sum += heights[i];
    }

    if (sum == 100) {
      sort(heights.begin(), heights.begin() + 7);
      for (int i = 0; i < 7; i++) {
        cout << heights[i] << "\n";
      }
      exit(0);
    }
  }

  for (int i = depth; i < N; i++) {
    swap(heights[i], heights[depth]);
    permutation(N, r, depth + 1);
    swap(heights[i], heights[depth]);
  }
}

int main() {
  for (int i = 0; i < N; i++) {
    cin >> heights[i];
  }

  permutation(N, N - 2, 0);
}