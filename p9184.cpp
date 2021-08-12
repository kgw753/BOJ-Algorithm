#include<bits/stdc++.h>
using namespace std;
int a, b, c;
int dp[22][22][22];
int w(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0) return 1;
    if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
    int &ret = dp[a][b][c];
    if(ret != 0) return ret;
    if(a < b && b < c) return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main(){
    while(true){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1) break;
        memset(dp, 0, sizeof(dp));
        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}