#include<bits/stdc++.h>
using namespace std;
#define MAX 51
int N, w, h;
vector<pair<int, int>> v(MAX);
vector<int> res(MAX);

int cmp(int idx){
    int ret = 0;
    for(int i = 0; i < N; i++){
        if(i == idx) continue;
        if(v[i].first > v[idx].first && v[i].second > v[idx].second) ret++;
    }
    return ret + 1;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> w >> h;
        v[i] = make_pair(w, h);
    }
    for(int i = 0; i < N; i++){
        res[i] = cmp(i);
    }
    for(int i = 0; i < N; i++) cout << res[i] << " ";
    cout << "\n";
}