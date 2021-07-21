#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N;
vector<pair<int, int>> v(MAX);
vector<int> ans(MAX, 0);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int value;
        cin >> value;
        v[i] = make_pair(value, i);
    }
    sort(v.begin(), v.begin() + N);
    int idx = 0;
    int prev = v[0].first;
    for(int i = 0; i < N; i++){
        if(prev != v[i].first) idx++;
        prev = v[i].first;
        ans[v[i].second] = idx;
    }
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << "\n";
}