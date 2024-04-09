#include <bits/stdc++.h>
using namespace std;
const int MAX = 54;
int N, L, R, days, _map[MAX][MAX];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
bool flag, visited[MAX][MAX];
vector<pair<int, int>> v;

void dfs(int y, int x) {
  if (visited[y][x]) {
    return;
  }
  visited[y][x] = true;
  v.push_back({y, x});

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
      continue;
    }

    int gap = abs(_map[ny][nx] - _map[y][x]);
    if (!visited[ny][nx] && gap >= L && gap <= R) {
      dfs(ny, nx);
    }
  }
}

void movePeople() {
  fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(bool), false);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!visited[i][j]) {
        v.clear();
        dfs(i, j);

        int sum = 0;
        for (pair<int, int> pos : v) {
          sum += _map[pos.first][pos.second];
        }
        for (pair<int, int> pos : v) {
          _map[pos.first][pos.second] = sum / v.size();
        }

        if (v.size() > 1) {
          flag = true;
        }
      }
    }
  }
}

void solve() {
  while (true) {
    flag = false;
    movePeople();

    if (!flag) {
      break;
    }

    days++;
  }

  cout << days << "\n";
}

void input() {
  cin >> N >> L >> R;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> _map[i][j];
    }
  }
}

int main() {
  input();
  solve();
}