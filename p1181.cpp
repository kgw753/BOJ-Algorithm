#include<bits/stdc++.h>
using namespace std;

bool cmp(string s1, string s2){
    if(s1.length() == s2.length()){
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main(){
    int N;
    vector<string> str;
    cin >> N;
    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        if(find(str.begin(), str.end(), input) == str.end()){
            str.push_back(input);
        }
    }

    sort(str.begin(), str.end(), cmp);

    for(int i = 0; i < str.size(); i++){
        cout << str[i] << "\n";
    }
}