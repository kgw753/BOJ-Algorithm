#include<bits/stdc++.h>
using namespace std;
#define MAX 5004
int N, Q, a, b, c;
vector<vector<pair<int, int>>> MAP(MAX, vector<pair<int, int>>());
vector<bool> visited(MAX, false);
int go(int usado, int start){
    fill(visited.begin(), visited.end(), false);
    visited[start] = true;
    int ret = -1;
    queue<int> q;
    q.push(start);
    while(q.size()){
        int here = q.front();
        visited[here] = true;
        q.pop();
        ret++;
        for(pair<int, int> p : MAP[here]){
            int there = p.first;
            int there_usado = p.second;
            if(!visited[there] && there_usado >= usado){
                q.push(there);
            }
        }
    }
    return ret;
}
int main(){
    cin >> N >> Q;
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b >> c;
        MAP[a].push_back({b, c});
        MAP[b].push_back({a, c});
    }
    for(int i = 0; i < Q; i++){
        cin >> a >> b;
        cout << go(a, b) << "\n";
    }
}