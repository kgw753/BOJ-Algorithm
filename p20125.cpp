#include <bits/stdc++.h>
using namespace std;
const int MAX = 1001;
int N;
char _map[MAX][MAX];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int getLength(pair<int, int> heartPos, int dir) {
  int y = heartPos.first;
  int x = heartPos.second;
  int len = 0;
  while (true) {
    y = y + dy[dir];
    x = x + dx[dir];
    if (y < 0 || x < 0 || y >= N || x >= N || _map[y][x] != '*') {
      break;
    }
    len++;
  }
  return len;
}

bool isHeart(int y, int x) {
  bool res = true;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (_map[ny][nx] != '*') {
      res = false;
    }
  }
  return res;
}

pair<int, int> findHeart() {
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < N - 1; j++) {
      if (isHeart(i, j)) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

void solve() {
  pair<int, int> heartPos = findHeart();
  int leftArm = getLength(heartPos, 2);
  int rightArm = getLength(heartPos, 0);
  int body = getLength(heartPos, 1);
  int leftLeg = getLength({heartPos.first + body, heartPos.second - 1}, 1);
  int rightLeg = getLength({heartPos.first + body, heartPos.second + 1}, 1);

  cout << heartPos.first + 1 << " " << heartPos.second + 1 << "\n";
  cout << leftArm << " " << rightArm << " " << body << " " << leftLeg << " "
       << rightLeg << "\n";
}
void input() {
  cin >> N;
  string str;
  for (int i = 0; i < N; i++) {
    cin >> str;
    for (int j = 0; j < N; j++) {
      _map[i][j] = str[j];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  input();
  solve();
}