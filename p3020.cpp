#include<bits/stdc++.h>
using namespace std;
#define MAX 500004
int N, H, a, b;
int v1[MAX], v2[MAX];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> H;
    for(int i = 0; i < N / 2; i++){
        cin >> a >> b;
        v1[a - 1]++, v2[H - b]++;
    }
    int mn = 1e9, cnt = 0;
    int n1 = N / 2, n2 = 0;
    for(int i = H - 1; i >= 0; i--){
        n2 += v1[i];
        if(mn > n1 + n2){
            cnt = 1;
            mn = n1 + n2;
        }
        else if(mn == n1 + n2) cnt++;
        n1 -= v2[i];
    }
    cout << mn << " " << cnt << "\n";
}