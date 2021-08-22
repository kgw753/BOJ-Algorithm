#include<bits/stdc++.h>
using namespace std;
int N, num;
char input[10]; 
stack<int> st;
vector<int> ans;
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%s", input);
        if(!strcmp(input, "push")){
            scanf("%d", &num);
            st.push(num);
        }
        if(!strcmp(input, "pop")){
            if(st.empty()) ans.push_back(-1);
            else {
                ans.push_back(st.top());
                st.pop();
            }
        }
        if(!strcmp(input, "size")) ans.push_back((int)st.size());
        if(!strcmp(input, "empty")) ans.push_back((int)st.empty());
        if(!strcmp(input, "top")){
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
        }
    }
    for(int i : ans) cout << i << "\n";
}