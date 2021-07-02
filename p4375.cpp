#include<bits/stdc++.h>
using namespace std;
int input;
int main(){
    while(scanf("%d", &input) != EOF){
        int one = 1;
        int ans = 1;
        while(one % input){
            one = (one * 10 + 1) % input;
            ans++;
        }
        printf("%d\n", ans);
    }
}