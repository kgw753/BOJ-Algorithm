#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int N;
vector<double> v(MAX, 0);
double ans, tmp;
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lf", &v[i]);
        ans = max(ans, v[i]);
    }
    tmp = 1;
    for(int i = 0; i < N; i++){
        if(v[i] * tmp < 1) tmp = 1;
        else{
            tmp *= v[i];
            ans = max(ans, tmp);
        }
    }
    printf("%.3lf\n", ans);
}