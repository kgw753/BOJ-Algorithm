#include<bits/stdc++.h>
using namespace std;
#define MAX 100004
int N, X, ans;
vector<int> v(MAX, 0);
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
    }
    cin >> X;
    sort(v.begin(), v.begin() + N);
    int l = 0, r = N - 1;

    while(l < r){
        if(v[l] + v[r] == X) ans++, r--;
        else if(v[l] + v[r] < X) l++;
        else if(v[l] + v[r] > X) r--;
    }
    cout << ans << "\n";
}