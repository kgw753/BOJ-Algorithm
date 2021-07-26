#include<bits/stdc++.h>
using namespace std;
#define MAX 300004
typedef long long ll;
int N, K, m, v;
ll sum;
vector<pair<int, int>> jw(MAX);
vector<int> bag(MAX, 0);

int main(){
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> m >> v;
        jw[i] = make_pair(m, v);
    }
    for(int i = 0; i < K; i++){
        cin >> bag[i];
    }
    sort(jw.begin(), jw.begin() + N);
    sort(bag.begin(), bag.begin() + K);
    priority_queue<int> pq;

    int idx = 0;
    for(int i = 0; i < K; i++){
        while(idx < N && bag[i] >= jw[idx].first) pq.push(jw[idx++].second);
        if(pq.size()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum << "\n";
}