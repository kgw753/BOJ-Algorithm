#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int A, B, C, D;
map<pair<int, int>, int> visited;
queue<pair<int, int>> q;
int bfs(int x, int y){
    q.push({x, y});
    visited[{x, y}] = 1;
    while(q.size()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if(!visited[{A, b}]){
            q.push({A, b});
            visited[{A, b}] = visited[{a, b}] + 1;
            if(A == C && b == D) break;
        } 
        if(!visited[{a, B}]){
            q.push({a, B});
            visited[{a, B}] = visited[{a, b}] + 1;
            if(a == C && B == D) break;
        }
        if(visited[{0, b}] == 0){
            q.push({0, b});
            visited[{0, b}] = visited[{a, b}] + 1; 
            if(0 == C && b == D) break;
        }
        if(visited[{a, 0}] == 0){
            q.push({a, 0});
            visited[{a, 0}] = visited[{a, b}] + 1;
            if(a == C && 0 == D) break;
        }
        if(visited[{min(a + b, A), max(0, b - (A - a))}] == 0){
            q.push({min(a + b, A), max(0, b - (A - a))});
            visited[{min(a + b, A), max(0, b - (A - a))}] = visited[{a, b}] + 1;
            if(min(a + b, A) == C && max(0, b - (A - a)) == D) break;
        }
        if(visited[{max(0, a - (B - b)), min(a + b, B)}] == 0){
            q.push({max(0, a - (B - b)), min(a + b, B)});
            visited[{max(0, a - (B - b)), min(a + b, B)}] = visited[{a, b}] + 1;
            if(max(0, a - (B - b)) == C && min(a + b, B) == D) break;
        }
    }
    if(visited[{C, D}]) return visited[{C, D}] - 1;
    else return -1;
}
int main(){
    cin >> A >> B >> C >> D;
    cout << bfs(0, 0) << "\n";
}