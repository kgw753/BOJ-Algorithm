#include<bits/stdc++.h>
using namespace std;
#define MAX 100001

int N, K;
int answer;

void bfs(int start){
    queue<pair<int, int>> q;
    vector<bool> visited(MAX, false);
    q.push(make_pair(start, 0));
    int now = -1;
    int cnt = -1;

    while(now != K){
        now = q.front().first;
        cnt = q.front().second;
        q.pop();
        visited[now] = true;
        
        if(now + 1 < MAX && visited[now + 1] == false)
            q.push(make_pair(now + 1, cnt + 1));
        if(now - 1 > -1 && visited[now - 1] == false)
            q.push(make_pair(now - 1, cnt + 1));
        if(now * 2 < MAX && visited[now * 2] == false)
            q.push(make_pair(now * 2, cnt + 1));
    }
    answer = cnt;
}

int main(){
    cin >> N >> K;   
    bfs(N);
    cout << answer << "\n";
}