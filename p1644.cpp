#include<bits/stdc++.h>
using namespace std;
int N, ans, sum;
vector<int> che;
vector<int> go(int max){
    vector<int> v;
    vector<bool> c(max, false);
    for(int i = 2; i <= max; i++){
        if(c[i]) continue;
        for(int j = 2 * i; j <= max; j += i){
            c[j] = true;
        }
    }
    for(int i = 2; i <= max; i++) if(!c[i]) v.push_back(i);
    return v;
}
int main(){
    cin >> N;
    che = go(N);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < che.size(); i++){
        sum += che[i];
        pq.push(che[i]);
        while(sum > N){
            sum -= pq.top();
            pq.pop();
        }
        if(sum == N) ans++;
    }
    cout << ans << "\n";
}