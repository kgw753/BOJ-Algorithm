#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int ans = 1;
        int one = 1;
        while(one % N){
            one = (one * 10 + 1) % N;
            ans++;
        }
        printf("%d\n", ans);
    }
}