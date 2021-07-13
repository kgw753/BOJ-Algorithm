#include<bits/stdc++.h>
using namespace std;
#define MAX 50
int N, M;
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> visited(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> house, chicken;
vector<int> chickenDist(MAX, 1e9);
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void printV(){
    cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%3d", visited[i][j]);
        }
        cout << "\n";
    }
}

void distBFS(int sy, int sx){
    queue<pair<int, int>> q;
    q.push(make_pair(sy, sx));
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || (ny == sy && nx == sx)) continue;
            if(visited[ny][nx] == 0){
                visited[ny][nx] = visited[y][x] + 1;
                q.push(make_pair(ny, nx));
            }
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 1) house.push_back(make_pair(i, j));
            else if(MAP[i][j] == 2) chicken.push_back(make_pair(i, j));
        }
    }

    for(int i = 0; i < house.size(); i++){
        for(int j = 0; j < chicken.size(); j++){
            int x = abs(house[j].second - chicken[i].second);
            int y = abs(house[j].first - chicken[i].first);
            chickenDist[i] = min(chickenDist[i],  x + y);
        }
    }
    sort(chickenDist.begin(), chickenDist.begin() + chicken.size());
    for(int i = 0; i < MAX; i++) cout << chickenDist[i] << " ";
    cout << "\n";
    cout << chickenDist[M - 1] << "\n";
}