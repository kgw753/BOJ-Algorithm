#include<bits/stdc++.h>
using namespace std;
int N, cnt;
string str;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        stack<char> st;
        cin >> str;
        for(int j = 0; j < str.length(); j++){
            if(!st.empty() && st.top() == str[j]) st.pop();
            else st.push(str[j]);
        }
        if(st.empty()) cnt++;
    }
    cout << cnt << "\n";
}