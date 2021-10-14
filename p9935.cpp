#include<bits/stdc++.h>
using namespace std;
string str, bomb, ans;
int main(){
    cin >> str >> bomb;
    int len = bomb.length();
    for(int i = 0; i < str.length(); i++){
        ans.push_back(str[i]);
        if(ans.length() < bomb.length()) continue;
        if(ans.substr(ans.length() - bomb.length()) == bomb){
            ans.erase(ans.length() - bomb.length());
        }
    }
    if(ans.empty()) cout << "FRULA\n";
    else cout << ans << "\n";
}