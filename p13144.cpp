#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
long long N, len, ans;
vector<int> v(MAX, 0);
vector<bool> visited(MAX, false);
queue<int> q;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> v[i];
    for(int i = 0; i < N; i++){
        while(visited[v[i]]){
            visited[v[q.front()]] = false;
            q.pop();
        }
        visited[v[i]] = true;
        q.push(i);
        ans += q.size();
    }
    cout << ans << "\n";
}