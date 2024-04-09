#include <bits/stdc++.h>
using namespace std;
const int MAX = 54;
int N, L, R, _map[MAX][MAX];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
bool flag, visited[MAX][MAX];

bool canMovePeople(pair<int, int> fromPos, pair<int, int> toPos) {
  int fromPeople = _map[fromPos.first][fromPos.second];
  int toPeople = _map[toPos.first][toPos.second];
  int peopleGap = abs(fromPeople - toPeople);

  return peopleGap >= L && peopleGap <= R;
}

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  vector<pair<int, int>> v;

  while (!q.empty()) {
    y = q.front().first;
    x = q.front().second;
    q.pop();

    if (visited[y][x]) {
      continue;
    }

    v.push_back({y, x});

    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (ny < 0 || nx < 0 || ny >= N || nx >= N) {
        continue;
      }
      if (!visited[ny][nx] && canMovePeople({y, x}, {ny, nx})) {
        q.push({ny, nx});
      }
    }
  }

  int sum = 0;
  for (pair<int, int> pos : v) {
    sum += _map[pos.first][pos.second];
  }

  int movedPopulation = sum / v.size();

  for (pair<int, int> pos : v) {
    _map[pos.first][pos.second] = movedPopulation;
  }

  if (v.size() > 1) {
    flag = true;
  }
}

void movePeople() {
  flag = false;
  fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(bool), false);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      bfs(i, j);
    }
  }
}

void solve() {
  int days = 0;

  while (true) {
    movePeople();

    if (!flag) {
      break;
    }
    days++;
  };

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