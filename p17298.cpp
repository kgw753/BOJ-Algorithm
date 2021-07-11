#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
int N;
vector<int> v(MAX), answer(MAX, -1);
stack<int> st;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];

        while(!st.empty() && v[st.top()] < v[i]){
            answer[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    for(int i = 0; i < N; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
}