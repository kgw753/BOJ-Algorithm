#include <bits/stdc++.h>
using namespace std;

const int MAX = 104;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int n, m, visited[MAX][MAX], miro[MAX][MAX];
queue<pair<int, int>> q;

void bfs(int sy, int sx) {
  q.push({sy, sx});
  miro[sy][sx] = 1;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    if (visited[y][x]) {
      continue;
    }
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny >= 0 && nx >= 0 && ny < n && nx < m && miro[ny][nx] &&
          !visited[ny][nx]) {
        miro[ny][nx] = miro[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%1d", &miro[i][j]);
    }
  }

  bfs(0, 0);

  cout << miro[n - 1][m - 1] << "\n";
}