#include<bits/stdc++.h>
using namespace std;
#define MAX 14
int N, mn = 1e9, mx = -1e9;
vector<int> num(MAX, 0), op(4, 0);
void calc(int val, int k){
    if(k == N) {
        mn = min(mn, val);
        mx = max(mx, val);
        return;
    }
    for(int i = 0; i < 4; i++){
        if(op[i] == 0) continue;
        op[i] -= 1;
        int tmp;
        if(i == 0) tmp = val + num[k];
        else if(i == 1) tmp = val - num[k];
        else if(i == 2) tmp = val * num[k];
        else if(i == 3) tmp = val / num[k];
        calc(tmp, k + 1);
        op[i] += 1;
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    for(int i = 0; i < 4; i++) cin >> op[i];
    calc(num[0], 1);
    cout << mx << "\n" << mn << "\n";
}