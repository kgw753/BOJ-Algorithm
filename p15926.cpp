#include<bits/stdc++.h>
using namespace std;
#define MAX 200004
int N, ans;
string str;
stack<int> st;
vector<int> check(MAX, 0);

int main(){
    cin >> N >> str;

    for(int i = 0; i < N; i++){
        if(str[i] == '('){
            st.push(i);
        }
        else if(str[i] == ')' && !st.empty()){
            check[st.top()] = check[i] = 1;
            st.pop();
        }
    }

    int tmp = 0;
    for(int i = 0; i < N; i++){
        if(check[i] == 0){
            ans = max(ans, tmp);
            tmp = 0;
        }
        else{
            tmp += check[i];
        }
    }
    cout << max(tmp, ans) << "\n";
}