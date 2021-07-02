#include<bits/stdc++.h>
using namespace std;
int N, M;
int main(){
    cin >> N >> M;
    vector<int> items(N, 0);
    for(int i = 0; i < N; i++) cin >> items[i];
    sort(items.begin(), items.end());
    int i = 0, j = N - 1, cnt = 0;
    while(i < j){
        if(items[i] + items[j] < M) i++;
        else if(items[i] + items[j] > M) j--;
        else if(items[i] + items[j] == M){
            j--;
            i++;
            cnt++;
        }
    }
    cout << cnt << "\n";
}