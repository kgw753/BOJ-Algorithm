#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, M, order, i, x, cnt;
vector<int> v(MAX, 0);
map<int, int> mp;
int main(){
    scanf("%d %d", &N, &M);
    while(M--){
        scanf("%d %d", &order, &i);
        i--;
        if(order == 1 || order == 2){
            scanf("%d", &x);
            if(order == 1) v[i] |= (1 << x);
            else if(order == 2) v[i] &= ~(1 << x);
        }
        else if(order == 3) v[i] <<= 1, v[i] &= ((1 << 21) - 1);
        else if(order == 4) v[i] >>= 1, v[i] &= ~1;
    }
    for(int i = 0; i < N; i++){
        if(mp[v[i]]++) continue;
        cnt++;
    }
    cout << cnt << "\n";
}