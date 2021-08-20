#include<bits/stdc++.h>
using namespace std;
int A, B, C, D;
map<pair<int, int>, int> visited;
queue<pair<int, int>> q;
void enqueue(int a, int b, int prev){
    if(visited[{a, b}]) return;
    q.push({a, b});
    visited[{a, b}] = prev + 1;
}
int bfs(int x, int y){
    q.push({x, y});
    visited[{x, y}] = 1;
    while(q.size()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        // Fill
        enqueue(0, b, visited[{a, b}]);
        enqueue(a, 0, visited[{a, b}]);
        // Empty
        enqueue(A, b, visited[{a, b}]);
        enqueue(a, B, visited[{a, b}]);
        // Move
        enqueue(max(0, a - (B - b)), min(B, b + a), visited[{a, b}]);
        enqueue(min(A, a + b), max(0, b - (A - a)), visited[{a, b}]);
    }
    if(visited[{C, D}]) return visited[{C, D}] - 1;
    else return -1;
}
int main(){
    cin >> A >> B >> C >> D;
    cout << bfs(0, 0) << "\n";
}