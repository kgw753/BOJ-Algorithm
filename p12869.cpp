#include<bits/stdc++.h>
using namespace std;
#define MAX 64
int N, scv[3], dp[MAX][MAX][MAX];
struct SCV{
    int a, b, c;
};
queue<SCV> q;
int go(int scv1, int scv2, int scv3){
    q.push({scv1, scv2, scv3});
    dp[scv1][scv2][scv3] = 1;
    vector<int> dmg({1, 3, 9});
    while(q.size()){
        if(dp[0][0][0]) break;
        scv1 = q.front().a;
        scv2 = q.front().b;
        scv3 = q.front().c;
        q.pop();
        do{
            int n1 = max(0, scv1 - dmg[0]);
            int n2 = max(0, scv2 - dmg[1]);
            int n3 = max(0, scv3 - dmg[2]);
            if(dp[n1][n2][n3]) continue;
            dp[n1][n2][n3] = dp[scv1][scv2][scv3] + 1;
            q.push({n1, n2, n3});
        }while(next_permutation(dmg.begin(), dmg.end()));
    }
    return dp[0][0][0] - 1;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> scv[i];
    cout << go(scv[0], scv[1], scv[2]) << "\n";
}