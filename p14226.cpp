#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int S, visited[MAX][MAX];

int bfs() {
  queue<pair<pair<int, int>, int>> q;
  q.push({{1, 0}, 0});
  visited[1][0] = true;

  while (!q.empty()) {
    int curr = q.front().first.first;
    int clip = q.front().first.second;
    int sec = q.front().second;
    q.pop();

    if (curr == S) {
      return sec;
    }

    if (curr > 0 && !visited[curr][curr]) {
      q.push({{curr, curr}, sec + 1});
      visited[curr][curr] = true;
    }

    if (clip > 0 && curr + clip < MAX && !visited[curr + clip][clip]) {
      q.push({{curr + clip, clip}, sec + 1});
      visited[curr + clip][clip] = true;
    }

    if (curr > 1 && !visited[curr - 1][clip]) {
      q.push({{curr - 1, clip}, sec + 1});
      visited[curr - 1][clip] = true;
    }
  }
  return -1;
}

void solve() { cout << bfs() << "\n"; }
void input() { cin >> S; }
int main() {
  input();
  solve();
}