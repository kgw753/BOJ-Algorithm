#include <bits/stdc++.h>
using namespace std;
const int MAX = 54;
int N, M, _map[MAX][MAX], res = 1e9;
vector<pair<int, int>> chickPos, homePos;
vector<vector<int>> chickIdxCombi;

void fillChickCombi(int start, vector<int> chickIdxList) {
  if (chickIdxList.size() == M) {
    chickIdxCombi.push_back(chickIdxList);
    return;
  }

  for (int i = start + 1; i < chickPos.size(); i++) {
    chickIdxList.push_back(i);
    fillChickCombi(i, chickIdxList);
    chickIdxList.pop_back();
  }
}

void solve() {
  fillChickCombi(-1, {});

  for (vector<int> chickIdxList : chickIdxCombi) {
    int sum = 0;
    for (pair<int, int> home : homePos) {
      int minDist = 1e9;
      int homeY = home.first;
      int homeX = home.second;

      for (int idx : chickIdxList) {
        int chickY = chickPos[idx].first;
        int chickX = chickPos[idx].second;
        int dist = abs(homeY - chickY) + abs(homeX - chickX);
        minDist = min(minDist, dist);
      }

      sum += minDist;
    }
    res = min(res, sum);
  }

  cout << res << "\n";
}

void input() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> _map[i][j];
      if (_map[i][j] == 1) {
        homePos.push_back({i, j});
      } else if (_map[i][j] == 2) {
        chickPos.push_back({i, j});
      }
    }
  }
}

int main() {
  input();
  solve();
}