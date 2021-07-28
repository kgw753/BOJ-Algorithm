#include<bits/stdc++.h>
using namespace std;
#define MAX 4000004
int N, ans, sum, p;
vector<int> v;
vector<bool> che(MAX, false);
int main(){
    cin >> N;
    for(int i = 2; i <= N; i++){
        if(che[i]) continue;
        for(int j = i * 2; j <= N; j += i) che[j] = true;
    }
    for(int i = 2; i <= N; i++) if(che[i] == false) v.push_back(i);
    for(int i = 0; i < v.size(); i++){
        sum += v[i];
        while(sum > N) sum -= v[p++];
        if(sum == N) ans++;
    }
    cout << ans << "\n";
}