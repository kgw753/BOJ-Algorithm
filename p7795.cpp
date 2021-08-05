#include<bits/stdc++.h>
using namespace std;
#define MAX 20004
int T, N, M, aPos, bPos, cnt;
vector<int> A(MAX, 0), B(MAX, 0);
vector<int> ans;
int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i < N; i++) cin >> A[i];
        for(int i = 0; i < M; i++) cin >> B[i];
        sort(A.begin(), A.begin() + N, greater<int>());
        sort(B.begin(), B.begin() + M, greater<int>());
        aPos = bPos = cnt = 0;
        while(bPos < M){
            while(A[aPos] > B[bPos] && aPos < N){
                cnt += (M - bPos);
                aPos++;
            }
            bPos++;
        }
        ans.push_back(cnt);
    }
    for(int i : ans) cout << i << "\n";
}