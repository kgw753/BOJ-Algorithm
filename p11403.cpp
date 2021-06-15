#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int N;
int MAP[MAX][MAX];
bool visited[MAX][MAX];
int answer[MAX][MAX];

void dfs(int from, int to){
    answer[from][to] = 1;
    visited[from][to] = true;

    for(int i = 0; i < N; i++){
        if(visited[from][i] == false && MAP[to][i] == 1){
            dfs(from, i);
        }
    }
}

int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP[i][j];
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(visited[i][j] == false && MAP[i][j] == 1){
                dfs(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
}