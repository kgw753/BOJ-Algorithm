#include<bits/stdc++.h>
using namespace std;
int N, s, e;
vector<int> st, et;
int parseTime(int t, int m){
    return ((t / 100) * 60) + (t % 100) + m;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s >> e;
        st.push_back(parseTime(s, -10));
        et.push_back(parseTime(e, 10));
    }
    st.push_back(22 * 60);
    sort(st.begin(), st.end());
    sort(et.begin(), et.end());
    int mx = st[0] - 600;
    for(int i = 0; i < N; i++){
        mx = max(mx, st[i + 1] - et[i]);
    }
    cout << mx << "\n";
}