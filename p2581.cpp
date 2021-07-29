#include<bits/stdc++.h>
using namespace std;
#define MAX 10004
int s, e, sum, mn = -1;
vector<bool> che(MAX, false);
int main(){
    cin >> s >> e;
    for(int i = 2; i <= e; i++){
        if(che[i]) continue;
        for(int j = i * 2; j <= e; j += i){
            che[j] = true;
        }
    }
    che[0] = che[1] = true;
    for(int i = s; i <= e; i++){
        if(che[i]) continue;
        if(mn == -1) mn = i;
        sum += i;
    }
    if(mn == -1) cout << -1 << "\n";
    else cout << sum << "\n" << mn << "\n";
}