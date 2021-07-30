#include<bits/stdc++.h>
using namespace std;
int num;
vector<int> ans;
vector<bool> che(123456 * 2 + 1, false);
int main(){
    for(int i = 2; i <= 123456 * 2; i++){
        if(che[i]) continue;
        for(int j = i * 2; j <= 123456 * 2; j += i){
            che[j] = true;
        }
    }
    while(true){
        cin >> num;
        if(num == 0) break;
        int cnt = 0;
        for(int i = num + 1; i <= num * 2; i++){
            if(che[i] == false) cnt++;
        }
        ans.push_back(cnt);
    }
    for(int a : ans) cout << a << "\n";
}