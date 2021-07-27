#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, sum, ans = -1e9;
vector<int> v(MAX, 0);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        sum += v[i];
        ans = max(sum, ans);
        if(sum < 0) sum = 0;
    }
    cout << ans << "\n";
}