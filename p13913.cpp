#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int N, K, pos;
vector<int> visited(MAX, 0);
vector<int> v;
void bfs(){
    queue<vector<int>> q;
    v.push_back(N);
    q.push(v);

    while(true){
        v = q.front();
        q.pop();
        pos = v[v.size() - 1];
        visited[pos] = 1;
        if(pos == K) break;
        if(pos - 1 >= 0 && visited[pos - 1] == 0){
            v.push_back(pos - 1);
            q.push(v);
            v.pop_back();
        }
        if(pos + 1 < MAX && visited[pos + 1] == 0){
            v.push_back(pos + 1);
            q.push(v);
            v.pop_back();
        }
        if(pos * 2 < MAX && visited[pos * 2] == 0){
            v.push_back(pos * 2);
            q.push(v);
            v.pop_back();
        }
    }
}

int main(){
    cin >> N >> K;
    if(N < K) bfs();
    else {
        for(int i = N; i >= K; i--) v.push_back(i);
    }
    cout << v.size() - 1 << "\n";
    for(int a : v) cout << a << " ";
    cout << "\n";
}