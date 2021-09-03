#include<bits/stdc++.h>
using namespace std;
#define MAX 64
int N, scv[3], visited[MAX][MAX][MAX];
struct SCV{
    int s1, s2, s3;
};
queue<SCV> q;
int go(int s1, int s2, int s3){
    visited[s1][s2][s3] = 1;
    q.push(SCV({s1, s2, s3}));
    while(q.size()){
        s1 = q.front().s1;
        s2 = q.front().s2;
        s3 = q.front().s3;
        q.pop();
        if(visited[0][0][0]) break;
        vector<int>dmg({1, 3, 9});
        do{
            int ns1 = max(0, s1 - dmg[0]);
            int ns2 = max(0, s2 - dmg[1]);
            int ns3 = max(0, s3 - dmg[2]);
            if(visited[ns1][ns2][ns3]) continue;
            visited[ns1][ns2][ns3] = visited[s1][s2][s3] + 1;
            q.push(SCV({ns1, ns2, ns3}));
        }while(next_permutation(dmg.begin(), dmg.end()));
    }
    return visited[0][0][0] - 1;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> scv[i];
    cout << go(scv[0], scv[1], scv[2]) << "\n";
}