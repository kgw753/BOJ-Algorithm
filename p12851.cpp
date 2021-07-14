#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int N, K, c;
vector<int> visited(MAX, 1e9);


void bfs(){
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    
    while(!q.empty()){
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(visited[pos] == 1e9) visited[pos] = cnt;
        if(pos == K && visited[pos] == cnt) c++;

        if(pos - 1 >= 0 && visited[pos - 1] >= cnt) q.push(make_pair(pos - 1, cnt + 1));
        if(pos + 1 < MAX && visited[pos + 1] >= cnt) q.push(make_pair(pos + 1, cnt + 1));
        if(pos * 2 < MAX && visited[pos * 2] >= cnt) q.push(make_pair(pos * 2, cnt + 1));
    }
}
int main(){
    cin >> N >> K;
    bfs();
    cout << visited[K] << "\n";
    cout << c << "\n";
}