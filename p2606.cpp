#include <bits/stdc++.h>
using namespace std;
#define MAX 104

int relations[MAX][MAX];
int res;
bool visited[MAX];
queue<int> q;

int main() {
  int N, M, a, b;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    relations[a][b] = relations[b][a] = 1;
  }

  q.push(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    if (visited[cur]) {
      continue;
    }

    visited[cur] = true;

    res++;

    for (int i = 1; i <= N; i++) {
      if (relations[cur][i] && !visited[i]) {
        q.push(i);
      }
    }
  }

  cout << res - 1 << "\n";
}