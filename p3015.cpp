#include<bits/stdc++.h>
using namespace std;
#define MAX 500004
typedef long long ll;
ll N, sum, input;
stack<pair<ll, ll>> st;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        int cnt = 1;
        while(!st.empty() && st.top().first <= input){
            sum += st.top().second;
            if(st.top().first == input){
                cnt = st.top().second + 1;
            }
            else{
                cnt = 1;
            }
            st.pop();
        }
        if(st.size()) sum += 1;
        st.push(make_pair(input, cnt));
    }
    cout << sum << "\n";
}