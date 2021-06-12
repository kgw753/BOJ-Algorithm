#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int cnt = 0;
    while(N % 5 != 0){
        cnt++;
        N -= 3;
    }

    (N < 0) ? cnt = -1 : cnt += N / 5;

    cout << cnt << "\n";
}