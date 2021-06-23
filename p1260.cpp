#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int N, M, V;
int MAP[MAX][MAX];

vector<int> visited(MAX, false);
vector<int> dfsAns;
vector<int> bfsAns;

void print(vector<int> v){
    for(int i: v){
        cout << i << " ";
    }
    cout << "\n";
}

void dfs(int now){
    if(visited[now] == true) return;
    visited[now] = true;
    dfsAns.push_back(now);

    for(int i = 1; i < N + 1; i++){
        if(visited[i] == false && MAP[now][i] == 1){
            dfs(i);
        }
    }
}

void bfs(int start){
    queue<int> q;
    vector<bool> visited(N + 1, false);
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 1; i < N + 1; i++){
            if(visited[i] == false && MAP[now][i] == 1){
                q.push(i);
                visited[i] = true;
            }
        }

        bfsAns.push_back(now);
    }
}

int main(){
    cin >> N >> M >> V;

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        MAP[a][b] = 1;
        MAP[b][a] = 1;
    }

    dfs(V);
    bfs(V);

    print(dfsAns);
    print(bfsAns);
}