#include <bits/stdc++.h>
using namespace std;
const int MAX = 54;
int N, a, b, relations[MAX][MAX], visited[MAX], scores[MAX], minDist = 1e9;

void bfs(int start) {
  queue<pair<int, int>> q;
  q.push({start, 0});
  visited[start] = 1;
  int maxDist = -1;

  while (!q.empty()) {
    int cur = q.front().first;
    int dist = q.front().second;
    q.pop();

    maxDist = max(maxDist, dist);

    for (int i = 1; i <= N; i++) {
      if (relations[cur][i] && !visited[i]) {
        q.push({i, dist + 1});
        visited[i] = 1;
      }
    }
  }

  scores[start] = maxDist;
}

int main() {
  cin >> N;
  while (true) {
    cin >> a >> b;
    if (a == -1 && b == -1) {
      break;
    }

    relations[a][b] = relations[b][a] = 1;
  }

  for (int i = 1; i <= N; i++) {
    memset(visited, 0, sizeof(visited));
    bfs(i);
    minDist = min(minDist, scores[i]);
  }

  vector<int> res;
  for (int i = 1; i <= N; i++) {
    if (minDist == scores[i])
      res.push_back(i);
  }
  cout << minDist << " " << res.size() << "\n";
  for (int r : res)
    cout << r << " ";
}