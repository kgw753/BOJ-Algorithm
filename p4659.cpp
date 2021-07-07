#include<bits/stdc++.h>
using namespace std;

string pw;
vector<string> result;
char aeiou[] = {'a', 'e', 'i', 'o', 'u'};

bool isMoum(char c){
    for(int i = 0; i < 5; i++){
        if(c == aeiou[i]) return true;
    }
    return false;
}

bool firstCheck(string str){
    for(int i = 0; i < str.length(); i++){
        if(isMoum(str[i])) return true;
    }
    return false;
}

bool secondCheck(string str){
    bool ret = true;
    for(int i = 0; i < str.length();){
        int cnt = 0;
        while(i < str.length() && isMoum(str[i])){
             cnt++, i++;
             if(cnt == 3){
                 ret = false;
                 break;
             }
        }
        cnt = 0;
        while(i < str.length() && !isMoum(str[i])){
            cnt++, i++;
             if(cnt == 3){
                 ret = false;
                 break;
             }
        }
    }
    return ret;
}

bool thirdCheck(string str){
    for(int i = 1; i < str.length(); i++){
        if(str[i - 1] == str[i]){
            if(str[i] == 'e' || str[i] == 'o') continue;
            return false;
        }
    }
    return true;
}

int main(){
    while(true){
        cin >> pw;
        if(pw == "end") break;
        string r = "<" + pw + "> is ";
        if(!firstCheck(pw) || !secondCheck(pw) || !thirdCheck(pw)){
            r += "not ";
        }
        r += "acceptable.\n";
        result.push_back(r);
    }

    for(string res: result){
        cout << res;
    }
}