#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, K, cnt;
vector<int> v(MAX, 0), visited(MAX, 0), sock;
int main(){
    cin >> N >> K;
    for(int i = 0; i < K; i++){
        cin >> v[i];
    }
    for(int i = 0; i < K; i++){
        if(visited[v[i]]) continue;
        if(sock.size() == N){
            int item = sock[0], idx = 0;
            for(int s : sock) {
                if(find(v.begin() + i + 1, v.end(), s) == v.end()){
                    item = s;
                    continue;
                }
                for(int j = i + 1; j < K; j++){
                    if(s == v[j] && idx < j){
                        idx = j;
                        item = s;
                    }
                }
            }
            sock.erase(find(sock.begin(), sock.end(), item));
            visited[item] = 0;
            cnt++;
            cout << i << " : " << item << "\n";
        }
        sock.push_back(v[i]);
        visited[v[i]] = 1;
    }
    cout << cnt << "\n";
}