#include <bits/stdc++.h>
using namespace std;
#define MAX 1004

int N, M;
bool visited[MAX];
bool relations[MAX][MAX];

void bfs(int start) {
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (visited[cur]) {
      continue;
    }

    visited[cur] = true;

    for (int i = 1; i <= N; i++) {
      if (relations[cur][i] && !visited[i]) {
        q.push(i);
      }
    }
  }
}

int main() {
  cin >> N >> M;

  int a, b;
  int res = 0;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    relations[a][b] = relations[b][a] = true;
  }

  for (int i = 1; i <= N; i++) {
    if (visited[i]) {
      continue;
    }

    bfs(i);
    res++;
  }

  cout << res << "\n";
}