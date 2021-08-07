#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N, num, len;
vector<int> lis(MAX, 0);
vector<pair<int, int>> ans(MAX);
stack<int> st;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        auto lowerPos = lower_bound(lis.begin(), lis.begin() + len, num);
        int idx = lowerPos - lis.begin();
        if(*lowerPos == 0) len++;
        *lowerPos = num;
        ans[i].first = idx;
        ans[i].second = num;
    }
    cout << len << "\n";
    for(int i = N - 1; i >= 0; i--){
        if(len - 1 == ans[i].first){
            st.push(ans[i].second);
            len--;
        }
    }
    while(st.size()){
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n";
}