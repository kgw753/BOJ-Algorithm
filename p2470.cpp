#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, arr[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int lo = 0, hi = N - 1;
    int ans = abs(arr[hi] + arr[lo]);
    pair<int, int> p = {arr[lo], arr[hi]};
    while(lo + 1 != hi){
        int tmp1 = abs(arr[hi] + arr[lo + 1]);
        int tmp2 = abs(arr[hi - 1] + arr[lo]);
        if(tmp1 < tmp2){
            lo++;
            if(tmp1 < ans){
                ans = tmp1;
                p = {arr[lo], arr[hi]};
            }
        }
        else{
            hi--;
            if(tmp2 < ans){
                ans = tmp2;
                p = {arr[lo], arr[hi]};
            }
        }
    }
    cout << p.first << " " << p.second << "\n";
}