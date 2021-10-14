#include<bits/stdc++.h>
using namespace std;
int N, p, d;
vector<pair<int, int>> v;
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> p >> d;
        v.push_back({d, p});
    }
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < N; i++){
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }
    int pay = 0;
    while(pq.size()){
        pay += pq.top();
        pq.pop();
    }
    cout << pay << "\n";
}