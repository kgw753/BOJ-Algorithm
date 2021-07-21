#include<bits/stdc++.h>
using namespace std;
#define MAX 22
int N, ret = 1e9;
string input;
vector<int> arr(MAX, 0);

void go(int here){
    if(here == N){
        int sum = 0;
        for(int i = 1; i <= (1 << (N - 1)); i *= 2){
            int cnt = 0;
            for(int j = 0; j < N; j++) if(arr[j] & i) cnt++;
            sum += min(cnt, N - cnt);
        }
        ret = min(ret, sum);
        return;
    }

    arr[here] = ~arr[here];
    go(here + 1);
    arr[here] = ~arr[here];
    go(here + 1);
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < N; j++){
            if(input[j] == 'T') arr[i] |= (1 << j);
        }
    }
    go(0);
    cout << ret << "\n";
}