#include<bits/stdc++.h>
using namespace std;
int a, b;
vector<int> che;
int gcd(int a, int b){
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}
int main(){
    scanf("%d:%d", &a, &b);
    int n = gcd(a, b);
    printf("%d:%d\n", a / n, b / n);
}