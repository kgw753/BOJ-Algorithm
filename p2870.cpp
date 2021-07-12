#include<bits/stdc++.h>
using namespace std;
int N;
string input, res;
vector<string> answer;

bool cmp(string s1, string s2){
    if(s1.length() == s2.length()) return s1 < s2;
    return s1.length() < s2.length();
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        int j = 0;
        while(j < input.length()){
            if(isdigit(input[j])){
                while(j < input.length() && isdigit(input[j])){
                    res += input[j++];
                }
                while(res.length() && res.front() == '0') res.erase(res.begin());
                if(res.length() == 0) res = "0";
                answer.push_back(res);
                res = "";
            }
            j++;
        }
    }
    sort(answer.begin(), answer.end(), cmp);
    for(string ans: answer) cout << ans << "\n";
}