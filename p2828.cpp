#include<bits/stdc++.h>
using namespace std;
int N, M, J, pos, cnt, l, r;
int main(){
    cin >> N >> M >> J;
    l = 1, r = M;
    for(int i = 0; i < J; i++){
        cin >> pos;
        while(pos < l || pos > r){
            if(pos > r) l++, r++;
            else l--, r--;
            cnt++;
        }
    }
    cout << cnt << "\n";
}