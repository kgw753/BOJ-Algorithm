#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b){
    if(b == 1) return a % c;
    ll tmp = go(a, b / 2) % c;
    tmp = tmp * tmp % c;
    if(b % 2) tmp = tmp * a % c;
    return tmp;
}
int main(){
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
}