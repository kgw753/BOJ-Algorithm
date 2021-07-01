#include<bits/stdc++.h>
using namespace std;
string input, res;
char mid;
int flag = 0;
vector<int> cnt('Z' - 'A' + 1, 0);
int main(){
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        cnt[input[i] - 'A']++;
    }
    for(int i = cnt.size() - 1; i > -1; i--){
        if(cnt[i] % 2){
            mid = char('A' + i);
            flag++;
            if(flag == 2) break;
        }
        for(int j = 0; j < cnt[i] / 2; j++){
            res += char('A' + i);
            res = char('A' + i) + res;
        }
    }
    if(flag == 1) res.insert(res.begin() + (res.length() / 2), mid);
    if(flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << res << "\n";
}