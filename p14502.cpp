#include<bits/stdc++.h>
using namespace std;
#define MAX 9
int N, M, answer, safe;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<vector<int>> MAP(MAX, vector<int>(MAX, 0));
vector<vector<int>> tmpMAP(MAX, vector<int>(MAX, 0));
vector<pair<int, int>> empt;
vector<pair<int, int>> virus;

void print(){
    cout << "\n";
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << tmpMAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void makeWalls(vector<pair<int, int>> v){
    for(int i = 0; i < static_cast<int>(v.size()); i++){
        tmpMAP[v[i].second][v[i].first] = 1;
    }
}

void goVirus(){
    queue<pair<int, int>> q;
    for(int i = 0; i < static_cast<int>(virus.size()); i++) q.push(virus[i]);
    
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
            if(tmpMAP[ny][nx] == 0){
                tmpMAP[ny][nx] = 2;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

void dfs(int x, int y){
    tmpMAP[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
        if(tmpMAP[ny][nx] == 0) {
            dfs(nx, ny);
            safe++;
        }
    }
}

void cntSafe(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(tmpMAP[i][j] == 0){
                dfs(j, i);
                safe++;
            }
        }
    }
}

void combi(int k, vector<pair<int, int>> v){
    if(v.size() == 3){
        tmpMAP = MAP;
        safe = 0;
        makeWalls(v);
        goVirus();
        cntSafe();
        answer = max(answer, safe);
        return;
    }

    for(int i = k; i < static_cast<int>(empt.size()); i++){
        v.push_back(empt[i]);
        combi(i + 1, v);
        v.pop_back();
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> MAP[i][j];
            if(MAP[i][j] == 0) empt.push_back(make_pair(j, i));
            else if(MAP[i][j] == 2) virus.push_back(make_pair(j, i));
        }
    }

    combi(0, vector<pair<int, int>>());
    cout << answer << "\n";
}