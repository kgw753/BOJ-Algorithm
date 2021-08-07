#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, a, b, len;
vector<pair<int, int>> v(MAX);
vector<int> res(MAX);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.begin() + N);
    for(int i = 0; i < N; i++){
        auto pos = lower_bound(res.begin(), res.begin() + len, v[i].second);
        if(*pos == 0) len++;
        *pos = v[i].second;
    }
    cout << N - len << "\n";
}