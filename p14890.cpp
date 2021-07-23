#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, L, ans = 0;
vector<vector<int>> MAP1(MAX, vector<int>(MAX, 0));
vector<vector<int>> MAP2(MAX, vector<int>(MAX, 0));

void go(vector<vector<int>> v){
    for(int i = 0; i < N; i++){
        int cnt = 1;
        int j;
        for(j = 0; j < N - 1; j++){
            if(v[i][j] == v[i][j + 1]) cnt++;
            else if(v[i][j] + 1 == v[i][j + 1] && cnt >= L) cnt = 1;
            else if(v[i][j] - 1 == v[i][j + 1] && cnt >= 0) cnt = -L + 1;
            else break;
        }
        if(j == N - 1 && cnt >= 0) ans++;
    }
}
int main(){
    cin >> N >> L;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> MAP1[i][j];
            MAP2[j][i] = MAP1[i][j];
        }
    }

    go(MAP1);
    go(MAP2);

    cout << ans << "\n";
}