#include<bits/stdc++.h>
using namespace std;
#define MAX 1000004
int N;
bool che[MAX];
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    che[0] = che[1] = true;
    for(int i = 2; i < MAX; i++){
        if(che[i]) continue;
        v.push_back(i);
        for(int j = i * 2; j < MAX; j += i){
            che[j] = true;
        }
    }
    
    while(true){
        cin >> N;
        if(N == 0) break;
        int idx = 0;
        int lo = v[idx];
        int hi = N - lo;
        bool found = false;
        while(lo <= hi){
            if(!che[hi] && lo + hi == N){
                found = true;
                break;
            }
            lo = v[++idx];
            hi = N - lo;
        }
        if(found) cout << N << " = " << lo << " + " << hi << "\n";
        else cout <<"Goldbach's conjecture is wrong.\n";
    }
}