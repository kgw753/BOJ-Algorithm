#include<bits/stdc++.h>
using namespace std;
#define MAX 55
int N, K, ans;
string input;
vector<string> str(MAX);
void combi(int now, int cnt, vector<bool> v){
    if(cnt == K){
        int tmp = 0;
        for(int i = 0; i < N; i++){
            int j;
            for(j = 0; j < str[i].length(); j++){
                if(v[str[i][j] - 'a'] == false) break;
            }
            if(j == str[i].length()) tmp++;
        }
        ans = max(ans, tmp);
    }

    for(int i = now; i < 'z' - 'a' + 1; i++){
        if(v[i]) continue;
        v[i] = true;
        combi(i + 1, cnt + 1, v);
        v[i] = false;
    }
}
int main(){
    cin >> N >> K;
    for(int i = 0; i < N ; i++){
        cin >> str[i];
        str[i] = str[i].substr(4, str[i].length() - 8);
    }

    if(K >= 5){
        vector<bool> ch('z' - 'a' + 1, false);
        ch['a' - 'a'] = ch['n' - 'a'] = ch['t' - 'a'] = ch['i' - 'a'] = ch['c' - 'a'] = true;
        combi(0, 5, ch);
    }
    cout << ans << "\n";
}