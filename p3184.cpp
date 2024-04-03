#include <bits/stdc++.h>
using namespace std;
const int MAX = 254;
int n, m, o, v;
char _map[MAX][MAX];
int visited[MAX][MAX];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  int to = 0, tv = 0;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    if (visited[y][x] || _map[y][x] == '#') {
      continue;
    }
    if (_map[y][x] == 'o') {
      to++;
    }
    if (_map[y][x] == 'v') {
      tv++;
    }
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (ny >= 0 && nx >= 0 && ny < n && nx < m && !visited[ny][nx] &&
          _map[ny][nx] != '#') {
        q.push({ny, nx});
      }
    }
  }

  if (to > tv) {
    o += to;
  } else {
    v += tv;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> _map[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      bfs(i, j);
    }
  }

  cout << o << " " << v << "\n";
}