#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, N, M, cnt;
int main(){
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N >> M;
        int r = 1, ans = 1;
        for(int i = M; i > M - N; i--){
            ans *= i;
            ans /= r++;
        }
        cout << ans << "\n";
    }
}