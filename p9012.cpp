#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    vector<bool> answer;
    for(int i = 0; i < T; i++){
        string input;
        cin >> input;

        stack<char> st;
        for(int j = 0; j < input.size(); j++){
            if(input[j] == ')'){
                if(st.empty()){
                    st.push(')');
                    break;
                }
                else{
                    st.pop();
                    continue;
                }
            }
            st.push(input[j]);
        }

        answer.push_back(st.empty());
    }

    string a;
    for(bool ans: answer){
        a = ans ? "YES" : "NO";
        cout << a << "\n";
    }
}