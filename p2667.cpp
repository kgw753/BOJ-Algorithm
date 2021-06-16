#include<bits/stdc++.h>
using namespace std;
#define MAX 25
int N;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

vector<pair<int, int>> v;
vector<int> answer;


void bfs(int y, int x, int cnt){
    queue<pair<int, int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;
    answer.push_back(1);
    
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
            if(visited[ny][nx] == false && MAP[ny][nx] == 1){
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                answer[cnt]++;
            }
        }
    }
}

int main(){
    cin >> N;
    int cnt = 0;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < input.length(); j++){
            int tmp = input[j] - '0';
            MAP[i][j] = tmp;
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(MAP[i][j] == 1 && visited[i][j] == false){
                bfs(i, j, cnt++);
            }
        }
    }

    sort(answer.begin(), answer.begin() + cnt);
    cout << cnt << "\n";
    for(int i = 0; i < cnt; i++){
        cout << answer[i] << "\n";
    }
}