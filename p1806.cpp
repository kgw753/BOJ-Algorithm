#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, S, arr[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int lo = 0, hi = 0;
    int sum = arr[0];
    int mn = 1e9;
    while(lo <= hi && hi < N){
        if(sum < S){
            sum += arr[++hi];
        }
        else if(sum == S){
            mn = min(mn, (hi - lo + 1));
            sum += arr[++hi];
        }
        else if(sum > S){
            mn = min(mn, (hi - lo + 1));
            sum -= arr[lo++];
        }
    }
    if(mn == 1e9) cout << 0 << "\n";
    else cout << mn << "\n";
}