#include<bits/stdc++.h>
using namespace std;
#define MAX 1004
int N, finIdx, len = 1;
vector<int> v(MAX, 0), cnt(MAX, 1), prevNum(MAX, -1);
void print(int idx){
    if(idx == -1) return;
    print(prevNum[idx]);
    cout << v[idx] << " ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && cnt[i] < cnt[j] + 1){
                cnt[i] = cnt[j] + 1;
                prevNum[i] = j;
                if(len < cnt[i]){
                    len = cnt[i];
                    finIdx = i;
                }
            }
        }
    }
    cout << len << "\n";
    print(finIdx);
    cout << "\n";
}