#include<bits/stdc++.h>
using namespace std;
int N, num;
vector<bool> che(10001, false);
vector<pair<int, int>> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i = 2; i <= 10000; i++){
        if(che[i]) continue;
        for(int j = i * 2; j <= 10000; j += i){
            che[j] = true;
        }
    }
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        int a = num, b = 0;
        for(int j = 0; j <= 10000; j++){
            if(che[j] || che[num - j]) continue;
            if(abs(a - b) > abs(j - (num - j))){
                a = j, b = num - j;
            }
        }
        ans.push_back(make_pair(a, b));
    }
    for(pair<int, int> p : ans) cout << p.first << " " << p.second << "\n";
}