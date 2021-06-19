#include<bits/stdc++.h>
using namespace std;

int era(int max, int k){
    vector<int> answer;
    vector<bool> che(max, false);
    int cnt = 0;
    for(int i = 2; i <= max; i++){
        if(che[i]) continue;
        for(int j = i; j <= max; j += i){
            if(che[j]) continue;
            che[j] = true;
            if(++cnt == k){
                return j;
            }
        }
    }

    return -1;
}
int main(){
    int N, K;
    cin >> N >> K;
    cout << era(N, K) << "\n";
}