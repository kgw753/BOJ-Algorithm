#include <bits/stdc++.h>
using namespace std;
const int MAX = 104;
int N, M, n, m, score = 1e9;
int relations[MAX][MAX], scores[MAX], visited[MAX];

void bfs(int idx) {
  queue<pair<int, int>> q;
  q.push({idx, 0});
  visited[idx] = 1;

  while (!q.empty()) {
    int cur = q.front().first;
    int dist = q.front().second;
    q.pop();

    scores[idx] += dist;

    for (int i = 1; i <= N; i++) {
      if (relations[i][cur] && !visited[i]) {
        q.push({i, dist + 1});
        visited[i] = 1;
      }
    }
  }
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> n >> m;
    relations[n][m] = relations[m][n] = 1;
  }

  for (int i = 1; i <= N; i++) {
    memset(visited, 0, sizeof(visited));
    bfs(i);
    score = min(score, scores[i]);
  }

  for (int i = 1; i <= N; i++) {
    if (scores[i] == score) {
      cout << i << "\n";
      return 0;
    }
  }
}