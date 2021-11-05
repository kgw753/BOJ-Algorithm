#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N, M, arr[MAX];
int pre, nxt, cnt;
int main(){
    cin >> N >> M;
    pre = 0, nxt = 1;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    int now;
    while(pre <= N && nxt <= N){
        now = arr[nxt] - arr[pre];
        if(now == M){
            cnt++;
            nxt++;
        }
        else if(now < M) nxt++;
        else pre++;
    }
    cout << cnt << "\n";
}