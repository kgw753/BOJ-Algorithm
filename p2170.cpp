#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N, a, b, mn, mx, sum;
vector<pair<int, int>> v(MAX);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }
    sort(v.begin(), v.begin() + N);
    mn = v[0].first, mx = v[0].second;
    for(int i = 1; i < N; i++){
        if(v[i].first > mx){
            sum += (mx - mn);
            mn = v[i].first;
            mx = v[i].second;
        }
        else if(mx >= v[i].first && mx <= v[i].second){
            mx = v[i].second;
        }
    }
    sum += (mx - mn);
    cout << sum << "\n";
}