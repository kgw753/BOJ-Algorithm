#include<bits/stdc++.h>
using namespace std;
#define MAX 20004
int T, N, M;
vector<int> A(MAX, 0), B(MAX, 0);
int main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < M; i++) cin >> B[i];
        sort(A.begin(), A.begin() + N);
        sort(B.begin(), B.begin() + M);
        int cnt = 0;
        for(int i = 0; i < N; i++){
            auto pos = lower_bound(B.begin(), B.begin() + M, A[i]);
            cnt += (int)(pos - B.begin());
        }
        cout << cnt << "\n";
    }
}