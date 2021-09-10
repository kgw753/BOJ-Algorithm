#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int T, N, M;
vector<int> v1(MAX), v2(MAX);
int check(int target){
    int lo = 0;
    int hi = N - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(v1[mid] == target) return 1;
        if(v1[mid] > target) hi = mid - 1; 
        if(v1[mid] < target) lo = mid + 1;
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
        for(int i = 0; i < N; i++) cin >> v1[i];
        cin >> M;
        for(int i = 0; i < M; i++) cin >> v2[i];
        sort(v1.begin(), v1.begin() + N);
        for(int i = 0; i < M; i++) cout << check(v2[i]) << " ";
        cout << "\n";
    }
}