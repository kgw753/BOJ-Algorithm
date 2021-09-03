#include<bits/stdc++.h>
using namespace std;
int N, flag;
string input, num;
vector<string> v;
bool cmp(string s1, string s2){
    if(s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        flag = 0;
        num = "";
        for(char c : input){
            if(c <= '9' && c >= '0'){
                flag = 1;
                if(c == '0' && num.empty()) continue;
                else num += c;
            }
            else if(flag){
                if(num.empty()) v.push_back("0");
                else v.push_back(num);
                num = "";
                flag = 0;
            }
        }
        if(flag) {
            if(num.empty()) v.push_back("0");
            else v.push_back(num);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(string str : v) cout << str << "\n";
}