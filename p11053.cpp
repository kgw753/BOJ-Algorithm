#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, ans;
vector<int> v(MAX, 0), cnt(MAX, 0);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i = 0; i < N; i++){
        int maxCnt = 0;
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && cnt[j] > maxCnt) maxCnt = cnt[j];
        }
        cnt[i] = maxCnt + 1;
        ans = max(ans, cnt[i]);
    }
    cout << ans << "\n";
}