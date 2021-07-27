#include<bits/stdc++.h>
using namespace std;
int N, p, d, ans;
vector<pair<int, int>> v;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p >> d;
        v.push_back(make_pair(d, p));
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }
    while(pq.size()){
        ans += pq.top();
        pq.pop();
    } 
    cout << ans << "\n";
}