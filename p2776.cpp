#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int T, N, M;
vector<int> A(MAX, 0), B(MAX, 0);
bool check(int target){
    int lo = 0;
    int hi = N - 1;
    int mid;
    while(lo <= hi){
        mid = (lo + hi) / 2;
        if(A[mid] == target) return 1;
        else if(A[mid] > target) hi = mid - 1;
        else if(A[mid] < target) lo = mid + 1;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> A[i];
        sort(A.begin(), A.begin() + N);
        cin >> M;
        for(int i = 0; i < M; i++) {
            cin >> B[i];
            cout << check(B[i]) << "\n";
        }
    }
}