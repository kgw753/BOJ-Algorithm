#include<bits/stdc++.h>
using namespace std;
#define MAX 104
int N, cnt;
vector<int> v(MAX, 0);
int main(){
    cin >> N;
    cnt = N;
    for(int i = 0; i < N; i++){
        cin >> v[i];
        if(v[i] == 1) cnt--;
    }
    for(int i = 0; i < N; i++){
        for(int j = 2; j <= sqrt(v[i]); j++){
            if(v[i] % j == 0){
                cnt--;
                break;
            } 
        }
    }
    cout << cnt << "\n";
}