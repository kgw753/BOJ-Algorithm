#include<bits/stdc++.h>
using namespace std;
bool res;
string input;
string str[] = {"pi", "ka", "chu"};
int main(){
    cin >> input;
    for(int i = 0; i < input.length(); i++){
        for(int j = 0; j < 3; j++){
            if(input.length() >= str[j].length() + i &&
            input.substr(i, str[j].length()) == str[j]){
                i += str[j].length() - 1;
                break;
            }
            if(j == 2) res = true;
        }
    }
    if(res) cout << "NO\n";
    else cout << "YES\n";
}