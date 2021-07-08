#include<bits/stdc++.h>
using namespace std;
int N, C, input;
map<int, int> cnt, seq;

bool cmp(pair<int, int> p1, pair<int, int> p2){
    if(p1.second == p2.second){
        return seq[p1.first] < seq[p2.first];
    }
    return p1.second > p2.second;
}

int main(){
    cin >> N >> C;

    for(int i = 0; i < N; i++){
        cin >> input;
        if(seq[input] == 0) seq[input] = i + 1;
        cnt[input]++;
    }

    vector<pair<int, int>> v(cnt.begin(), cnt.end());
    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].second; j++){
            cout << v[i].first << " ";
        }
    }
    cout << "\n";
}