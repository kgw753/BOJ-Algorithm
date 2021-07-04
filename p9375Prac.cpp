#include<bits/stdc++.h>
using namespace std;
int tc, n;
vector<int> answer;
string str1, str2;
int main(){
    cin >> tc;
    while(tc--){
        cin >> n;
        map<string, int> MAP;
        for(int i = 0; i < n; i++){
            cin >> str1 >> str2;
            MAP[str2]++;
        }
        int ans = 1;
        for(auto m : MAP){
            ans *= m.second + 1;
        }
        answer.push_back(ans - 1);
    }
    for(int ans: answer) cout << ans << "\n";
}