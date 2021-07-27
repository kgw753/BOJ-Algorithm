#include<bits/stdc++.h>
using namespace std;
string input, del, ans;
int main(){
    cin >> input >> del;
    for(int i = 0; i < input.length(); i++){
        ans += input[i];
        if(ans.length() >= del.length() && ans.substr(ans.length() - del.length()) == del){
            ans.erase(ans.length() - del.length());
        }
    }
    if(ans.length()) cout << ans << "\n";
    else cout << "FRULA\n";
}