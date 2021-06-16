#include<bits/stdc++.h>
using namespace std;
int main(){
    long long S;
    cin >> S;
    int N = 0;
    long long sum = 0;
    while(sum <= S){
        sum += ++N;
    }
    cout << N - 1 << "\n";
}